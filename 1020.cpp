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
const int N=30+5;
const int mod=1e9+7;
const db eps=1e-6;                                                                            
const db pi=acos(-1.0);
int n,in[N],post[N],le[N],ri[N],x;
vector<int>node[35];
int work(int l,int r){
    if(l>r) return 0;
    if(l==r) return in[l];
    int pos=l;
    rep(i,l,r) if(post[in[i]]>post[in[pos]]) 
        pos=i;
    le[in[pos]]=work(l,pos-1);
    ri[in[pos]]=work(pos+1,r);
    return in[pos];
}
void dfs(int x,int d){
    node[d].push_back(x);
    if(le[x]) dfs(le[x],d+1);
    if(ri[x]) dfs(ri[x],d+1);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n;
    int end;
    rep(i,1,n){
        cin>>x;
        post[x]=i;
        if(i==n) end=x;
    }
    rep(i,1,n) cin>>in[i];
    work(1,n);
    dfs(end,1);
    cout<<end;
    rep(i,2,n){
        if(node[i].size()==0) break;
        for(auto j:node[i]) cout<<" "<<j;
    }
}