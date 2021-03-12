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
int n,m,col[N],k,vis[10005];
vector<int>tr[10005];
bool dfs(int u){
    vis[u]=1;
    for(auto v:tr[u]) 
        if(col[v]==col[u]) return 0;
    for(auto v:tr[u]){
        if(vis[v]) continue;
        if(!dfs(v)) return 0;
    }
    return 1;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n>>m;
    rep(i,1,m){
        int u,v;
        cin>>u>>v;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    cin>>k;
    rep(i,1,k){
        set<int>s;
        rep(i,0,n-1){
            cin>>col[i];
            s.insert(col[i]);
            vis[i]=0;
        }
        if(dfs(0)) cout<<s.size()<<"-coloring"<<endl;
        else cout<<"No"<<endl;
    }
}