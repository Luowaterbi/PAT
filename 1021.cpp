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
int n,cycle,col[N],far,dep;
vector<int>tr[N];
void dfs1(int u,int fa){
    for(auto v:tr[u]){
        if(v==fa) continue;
        if(col[v]){
            cycle=1;
            continue;
        }
        col[v]=col[u];
        dfs1(v,u);
    }
}
void dfs2(int u,int fa,int d){
    for(auto v:tr[u]){
        if(v==fa) continue;
        dfs2(v,u,d+1);
    }
    if(d>dep){
        far=u;
        dep=d;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n;
    repp(i,1,n){
        int u,v;
        cin>>u>>v;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    int color=0;
    rep(i,1,n){
        if(!col[i]){
            col[i]=++color;
            dfs1(i,0);
        }
    }
    if(cycle==1||color!=1){
        printf("Error: %d components\n",color);
        return 0;
    }
    dep=0;
    dfs2(1,0,0);
    dep=0;
    dfs2(far,0,0);
    int ldep=dep;
    vector<int>ans;
    rep(i,1,n){
        // if(tr[i].size()==1){
            dep=0;
            dfs2(i,0,0);
            if(dep==ldep) ans.push_back(i);
        // }
    }
    for(auto i:ans){
        cout<<i<<endl;
    }
}