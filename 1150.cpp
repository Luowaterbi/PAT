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
const int N=200+5;
const int mod=1e9+7;
const db eps=1e-6;                                                                            
const db pi=acos(-1.0);
int n,m,dis[N][N],vis[N],simple,path,c[N],cycle,nn,k,na;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n>>m;
    rep(i,1,m){
        int u,v,w;
        cin>>u>>v>>w;
        dis[u][v]=dis[v][u]=w;
    }
    cin>>k;
    int minpath=INF,minpos;
    rep(j,1,k){
        printf("Path %d: ",j);
        rep(i,1,n) vis[i]=0;
        cin>>nn;
        path=simple=na=cycle=0;
        rep(i,1,nn){
            cin>>c[i];
            ++vis[c[i]];
            if(i!=1){
                if(!dis[c[i]][c[i-1]]) na=1;
                else path+=dis[c[i]][c[i-1]];
            }
        }
        if(na) printf("NA (Not a TS cycle)\n");
        else{
            int cnt=0;
            rep(i,1,n){
                if(vis[i]>2) simple=1;
                if(vis[i]==2) cnt++;
                if(vis[i]==0) cycle=1;
            }
            if(c[1]!=c[nn]) cycle=1;
            printf("%d ",path);
            if(cycle) printf("(Not a TS cycle)\n");
            else{
                if(path<minpath){
                    minpath=path;
                    minpos=j;
                }
                if(simple==0&&cnt==1) printf("(TS simple cycle)\n");
                else printf("(TS cycle)\n");
            }
        }
    }
    printf("Shortest Dist(%d) = %d\n",minpos,minpath);
}