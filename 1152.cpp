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
const db eps=1e-6;                                                                            
const db pi=acos(-1.0);
int n,k;
string s;
bool judge(ll x){
    if(x==1) return 0;
    rep(i,2,sqrt(x)){
        if(x%i==0) 
            return 0;
    }
    return 1;
}
void print(ll x){
    int cnt=0;
    while(x){
        ++cnt;
        x/=10;
    }
    rep(i,1,k-cnt) cout<<0;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif 
    cin>>n>>k>>s;
    ll res=0,mod=1;
    repp(i,0,k-1){
        res=res*10+s[i]-'0';
        mod=mod*10;
    }
    rep(i,0,n-k){
        res=res%mod*10+s[i+k-1]-'0';
        if(judge(res)){
            print(res);
            cout<<res<<endl;
            return 0;
        }
    }
    cout<<404<<endl;

}