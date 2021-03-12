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
const int N=2e5+5;
const int mod=1e9+7;
const db eps=1e-6;                                                                            
const db pi=acos(-1.0);
int n,t[1005],maxn,minn;
vector<int>path;
void dfs(int u){
    path.push_back(u);
    int lc=u<<1,rc=lc|1;
    if(lc>n){
        repp(i,0,path.size()){
            if(i!=0){
                if(t[path[i-1]]>t[path[i]]) maxn=1;
                if(t[path[i-1]]<t[path[i]]) minn=1;
                cout<<" "<<t[path[i]];
            }
            else cout<<t[path[i]];
        }
        cout<<endl;
    }
    if(rc<=n) dfs(rc);
    if(lc<=n) dfs(lc);
    path.pop_back(); 
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n;
    rep(i,1,n) cin>>t[i];
    maxn=0,minn=0;
    dfs(1);
    if(maxn==1&&minn==1) cout<<"Not Heap"<<endl;
    else cout<<(maxn==1?"Max Heap":"Min Heap")<<endl;
}