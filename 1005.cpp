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
string s[15];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    s[0]="zero";
    s[1]="one";
    s[2]="two";
    s[3]="three";
    s[4]="four";
    s[5]="five";
    s[6]="six";
    s[7]="seven";
    s[8]="eight";
    s[9]="nine";
    string num;
    cin>>num;
    int sum=0;
    for(auto i:num){
        sum+=i-'0';
    }
    stack<string>ans;
    while(1){
        ans.push(s[sum%10]);
        sum/=10;
        if(sum==0) break;
    }
    while(ans.size()){
        cout<<ans.top();
        ans.pop();
        if(ans.size()) cout<<" ";
    }
}