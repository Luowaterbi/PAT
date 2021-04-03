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
int n,m,maxn,minn,t[N];
void dfs(int u){
    int lc=u<<1,rc=lc|1;
    if(lc>n) return ;
    if(t[lc]>t[u]) minn=1;
    if(t[lc]<t[u]) maxn=1;
    dfs(lc);
    if(rc<=n){
        if(t[rc]>t[u]) minn=1;
        if(t[rc]<t[u]) maxn=1;
        dfs(rc);
    }
}
vector<int>ans;
void post(int u){
    int lc=u<<1,rc=lc|1;
    if(lc<=n) post(lc);
    if(rc<=n) post(rc);
    ans.push_back(t[u]);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>m>>n;
    rep(i,1,m){
        rep(j,1,n) cin>>t[j];
        ans.clear();
        maxn=minn=0;
        dfs(1);
        if(maxn==1&&minn==1) cout<<"Not Heap\n";
        else cout<<(maxn?"Max Heap\n":"Min Heap\n");
        post(1);
        repp(j,0,n){
            if(j==0) cout<<ans[j];
            else cout<<" "<<ans[j];
        }
        cout<<"\n";
    }
}