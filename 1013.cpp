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
const int N=1e3+5;
const int mod=1e9+7;
const db eps=1e-6;                                                                            
const db pi=acos(-1.0);
int n,k,m,x,vis[N];
vector<int>tr[N];
void dfs(int u){
    vis[u]=1;
    for(auto v:tr[u]){
        if(vis[v]) continue;
        dfs(v);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n>>m>>k;
    rep(i,1,m){
        int u,v;
        cin>>u>>v;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    rep(i,1,k){
        ms(vis,0);
        cin>>x;
        vis[x]=1;
        int cnt=0;
        rep(j,1,n){
            if(!vis[j]){
                ++cnt;
                dfs(j);
            } 
        }    
        cout<<cnt-1<<endl;   
    }
}