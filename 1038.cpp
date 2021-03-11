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
const int N=1e4+5;
const int mod=1e9+7;
const db eps=1e-6;                                                                            
const db pi=acos(-1.0);
int n;
string s[N];
bool cmp(const string &A,const string &B){
    // int la=A.size(),lb=B.size();
    // if(la==lb) return A<B;
    // if(la<lb){
    //     if(B.substr(0,la)==A) return B[la]>B[0];
    //     return A<B;
    // }else{
    //     if(A.substr(0,lb)==B)return A[lb]<A[0];
    //     return A<B;
    // }
    return A+B<B+A;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n;
    rep(i,1,n) cin>>s[i];
    sort(s+1,s+n+1,cmp);
    rep(i,2,n) s[1]+=s[i];
    
    int j=0;
    while(j<s[1].size()&&s[1][j]=='0') ++j;
    if(j==s[1].size()) cout<<0<<endl;
    else cout<<s[1].substr(j)<<endl;
            
}