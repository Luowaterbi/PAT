#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define All(x) (x).begin(),(x).end() 
#define pii pair<int,int>
#define mp make_pair
#define INF 0x3f3f3f3f
using namespace std;
const int N=2e2+5;
int n,m,sum;
int dis[N][N],vis[N];
vector<int>path;
void dfs(int u){
    vis[u]=1;
    path.push_back(u);
    int pos=-1;
    rep(i,1,n){
        if(vis[i]||dis[u][i]==INF) continue;
        if(pos==-1||dis[u][i]<dis[u][pos]) pos=i;
    }
    if(pos==-1) return ;
    sum+=dis[u][pos];
    dfs(pos);
}
int main(){
    cin>>n>>m;
    memset(dis,INF,sizeof(dis));
    rep(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        dis[u][v]=dis[v][u]=w;
    }
    rep(k,0,n)
        rep(i,0,n)
            rep(j,0,n)
                dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
    sum=0;
    dfs(0);
    int l=path.size();
    rep(i,0,l-1){
        if(i==0) cout<<path[i];
        else cout<<" "<<path[i];
    }
    cout<<"\n";
    if(l==n+1) cout<<sum;
    else{
        int fir=1;
        rep(i,1,n) if(!vis[i]){
            if(fir){
                cout<<i;
                fir=0;
            }else cout<<" "<<i;
        }
    }
}