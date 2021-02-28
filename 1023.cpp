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
string s1,s2;
vector<int>cnt1(10),cnt2(10);
int num1[25],num2[25];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>s1;
    int l=s1.size();
    repp(i,0,l){
        num1[i+1]=s1[i]-'0';
        ++cnt1[num1[i+1]];
    }
    lep(i,l,1){
        num2[i]+=num1[i]*2;
        num2[i-1]+=num2[i]/10;
        num2[i]%=10;
        ++cnt2[num2[i]];
    }
    if(num2[0]) cnt2[num2[0]]++;
    cout<<(cnt1==cnt2?"Yes":"No")<<endl;
    if(num2[0]) cout<<num2[0];
    rep(i,1,l) cout<<num2[i];
}