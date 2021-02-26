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
int n,a[N],pre[N],l,r;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n;
    int flag=1;
    rep(i,1,n){
        cin>>a[i];
        pre[i]=a[i]+pre[i-1];
        if(a[i]>=0) flag=0;
    }
    if(flag){
        cout<<0<<" "<<a[1]<<" "<<a[n];
        return 0;
    }
    int minn=0,ans=-INF;
    rep(i,1,n){
        if(pre[i]-pre[minn]>ans){
            ans=pre[i]-pre[minn];
            l=minn+1,r=i;
        }
        if(pre[i]<pre[minn]) minn=i;
    }
    cout<<ans<<" "<<a[l]<<" "<<a[r];
}