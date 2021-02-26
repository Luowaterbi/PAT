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
int k,a;
db ans[1005],b;
set<int>s;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>k;
    rep(i,1,k){
        cin>>a>>b;
        ans[a]+=b;
        s.insert(a);
    }
    cin>>k;
    rep(i,1,k){
        cin>>a>>b;
        ans[a]+=b;
        if(ans[a]!=0) s.insert(a);//这一项为0的时候不输出
        else s.erase(a);
    }
    cout<<s.size();
    stack<int>s1;
    stack<db>s2;
    for(auto i:s){
        s1.push(i);
        s2.push(ans[i]);
    }
    while(s1.size()){
        printf(" %d %.1lf",s1.top(),s2.top());
        s1.pop();
        s2.pop();
    }
}