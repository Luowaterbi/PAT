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
const int N=1e6+5;
const int mod=1e9+7;
const db eps=1e-6;                                                                            
const db pi=acos(-1.0);
int n[2],k[2][N];
db a[2][N],ans[N]; 
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    rep(i,0,1){
        cin>>n[i];
        rep(j,1,n[i]) cin>>k[i][j]>>a[i][j]; 
    }
    rep(i,1,n[0]){
        rep(j,1,n[1]) ans[k[0][i]+k[1][j]]+=a[0][i]*a[1][j];
    }
    int cnt=0;
    lep(i,1000000,0) if(ans[i]!=0) ++cnt;
    cout<<cnt;
    lep(i,1000000,0) if(ans[i]!=0) cout<<" "<<i<<" "<<fixed<<setprecision(1)<<ans[i];
}