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
int n,m,s,t,vis[505];
pll ans;
vector<int>final_path;
vector<pair<int,pll>>tr[505];
void dfs(int u,pll data,vector<int>path){
    if(u==t){
        if(data<ans){
            ans=data;
            final_path=path;
        }
        return ;
    }
    for(auto e:tr[u]){
        int v=e.first;
        ll dis=e.second.first,cost=e.second.second;
        if(vis[v]) continue;
        vis[v]=1;
        path.push_back(v);
        dfs(v,mp(data.first+dis,data.second+cost),path);
        path.pop_back();
        vis[v]=0;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n>>m>>s>>t;
    int u,v;
    pll w;
    rep(i,1,m){
        cin>>u>>v>>w.first>>w.second;
        tr[u].push_back(mp(v,w));
        tr[v].push_back(mp(u,w));
    }
    vector<int>path;
    path.clear();
    path.push_back(s);
    vis[s]=1;
    ans.first=ans.second=INFF;
    dfs(s,mp(0,0),path);
    for(auto i:final_path) cout<<i<<" ";
    cout<<ans.first<<" "<<ans.second<<endl;
}