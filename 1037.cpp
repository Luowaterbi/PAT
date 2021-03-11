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
int nc,np,pro[N],cou[N];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>nc;
    rep(i,1,nc) cin>>cou[i];
    cin>>np;
    rep(i,1,np) cin>>pro[i];
    sort(cou+1,cou+nc+1);
    sort(pro+1,pro+np+1);
    int headc=1,headp=1,tailc=nc,tailp=np;
    ll sum=0;
    while(tailc>=headc&&tailp>=headp){
        ll tmp=1LL*cou[tailc]*pro[tailp];
        if(tmp<=0) break;
        sum+=tmp;
        tailc--,tailp--;
    }
    while(headc<=tailc&&headp<=tailp){
        ll tmp=1LL*cou[headc]*pro[headp];
        if(tmp<=0) break;
        sum+=tmp;
        headc++,headp++;
    }
    cout<<sum<<endl;
}