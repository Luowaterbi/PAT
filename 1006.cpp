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
int cal(string s,int pos){
    return (s[pos]-'0')*10+(s[pos+1]-'0');
}
int n,st=INF,ed=0;
string t1,t2,name,ans1,ans2;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n;
    rep(i,1,n){
        cin>>name>>t1>>t2;
        int tt1=cal(t1,0)*3600+cal(t1,3)*60+cal(t1,6),tt2=cal(t2,0)*3600+cal(t2,3)*60+cal(t2,6);
        if(tt1<st){
            st=tt1;
            ans1=name;
        }
        if(tt2>ed){
            ed=tt2;
            ans2=name;
        }
    }
    cout<<ans1<<" "<<ans2;
}