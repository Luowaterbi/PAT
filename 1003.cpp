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
int n,m,s,t,c[N],minn=INF,cnt,maxn=0,vis[N];
vector<pii>tr[N];
void dfs(int u,int len,int sum){
    if(u==t){
        if(len>minn) return ;
        if(len<minn){
            minn=len;
            maxn=sum;
            cnt=1;
        }else{
            maxn=max(maxn,sum);
            ++cnt;
        }
        return ;
    }
    for(auto e:tr[u]){
        int v=e.first,w=e.second;
        if(vis[v]) continue;
        vis[v]=1;
        dfs(v,len+w,sum+c[v]);
        vis[v]=0;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n>>m>>s>>t;
    rep(i,0,n-1) cin>>c[i];
    rep(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        tr[u].push_back(mp(v,w));
        tr[v].push_back(mp(u,w));
    }
    vis[s]=1;
    dfs(s,0,c[s]);
    cout<<cnt<<" "<<maxn;
}