#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repp(i,a,b) for(int i=(a);i<(b);i++)
#define lep(i,a,b) for(int i=(a);i>=(b);i--) 
#define lepp(i,a,b) for(int i=(a);i>(b);i--)
#define pii pair<int,int>
#define pll pair<long long,long long>
#define mp make_pair
#define All(x) x.begin(),x.end() 
#define ms(a,b) memset(a,b,sizeof(a)) 
#define INF 0x3f3f3f3f
#define INFF 0x3f3f3f3f3f3f3f3f
#define multi int T;scanf("%d",&T);while(T--) 
using namespace std;
typedef long long ll;
typedef double db;
const int N=1e4+5;
const int mod=1e9+7;
const db eps=1e-6;                                                                            
const db pi=acos(-1.0);
int n,m,preorder[N],inorder[N];
map<int,int>inpos,prepos;
set<int>num;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>m>>n;
    rep(i,1,n){
        cin>>inorder[i];
        inpos[inorder[i]]=i;
        num.insert(inorder[i]);
    }
    rep(i,1,n){
        cin>>preorder[i];
        prepos[preorder[i]]=i;
    }
    int u,v;
    rep(i,1,m){
        cin>>u>>v;
        if(num.find(u)==num.end()&&num.find(v)==num.end()) printf("ERROR: %d and %d are not found.\n",u,v);
        else if(num.find(u)==num.end()) printf("ERROR: %d is not found.\n",u);
        else if(num.find(v)==num.end()) printf("ERROR: %d is not found.\n",v);
        else{
            int l=min(inpos[u],inpos[v]),r=max(inpos[u],inpos[v]);
            int minn=n;
            rep(i,l,r){
                minn=min(minn,prepos[inorder[i]]);
            }
            if(minn==prepos[u]) printf("%d is an ancestor of %d.\n",u,v);
            else if(minn==prepos[v]) printf("%d is an ancestor of %d.\n",v,u);
            else{
                printf("LCA of %d and %d is %d.\n",u,v,preorder[minn]);
            }
        }
    }
}