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
int n,m,k,dep=0,ans[N];
vector<int>tr[N];
void dfs(int u,int d){
    dep=max(dep,d);
    if(tr[u].size()==0){
        ++ans[d];
        return ;
    }
    for(auto v:tr[u]) 
        dfs(v,d+1);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n>>m;
    rep(i,1,m){
        int son,fa;
        cin>>fa>>k;
        rep(j,1,k){
            cin>>son;
            tr[fa].push_back(son);
        }
    }
    dfs(1,1);
    rep(i,1,dep){
        if(i!=1) cout<<" ";
        cout<<ans[i];
    }
}