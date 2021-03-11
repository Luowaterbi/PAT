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
map<string,string>lis;
map<string,int>cnt;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    string s1,s2,cur,nxt;
    int n;
    char c;
    cin>>s1>>s2>>n;
    rep(i,1,n){
        cin>>cur>>c>>nxt;
        lis[cur]=nxt;
    }
    while(s1!="-1"){
        cnt[s1]=1;
        s1=lis[s1];
    }
    string ans="-1";
    while(s2!="-1"){
        if(cnt.find(s2)!=cnt.end()){
            ans=s2;
            break;
        }
        s2=lis[s2];
    }
    cout<<ans<<endl;
}