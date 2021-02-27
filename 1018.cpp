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
int cmax,n,s,m,c[N],vis[N],anstake,ansback,anslen=INF;
struct node{
    vector<int>path;
    int take,back,len;
}ans;
vector<pii>tr[N];
void dfs(int u,node cur){
    vis[u]=1;
    if(u==s){
        if(cur.len<ans.len) ans=cur;
        else if(cur.len==ans.len){
            if(cur.take<ans.take) ans=cur;
            else if(cur.take==ans.take){
                if(cur.back<ans.back) ans=cur;
            }
        }
        return ;
    }
    for(auto e:tr[u]){
        int v=e.first,w=e.second;
        if(vis[v]) continue;
        int tmp=cur.back+c[v]-cmax/2;
        cur.path.push_back(v);
        if(tmp>=0) dfs(v,{cur.path,cur.take,tmp,cur.len+w});
        else dfs(v,{cur.path,cur.take-tmp,0,cur.len+w});
        vis[v]=0;
        cur.path.pop_back();
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>cmax>>n>>s>>m;
    rep(i,1,n) cin>>c[i];
    rep(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        tr[u].push_back(mp(v,w));
        tr[v].push_back(mp(u,w));
    }
    node cur;
    cur.path.clear();
    cur.take=ans.len=cur.back=0;
    ans.len=INF;
    dfs(0,cur);
    cout<<ans.take<<" "<<0;
    for(auto u:ans.path){
        cout<<"->"<<u;
    }
    cout<<" "<<ans.back<<endl;
}