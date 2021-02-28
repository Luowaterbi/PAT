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
string s;
int k;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>s>>k;
    int l=s.size();
    vector<int>n1,n2;
    repp(i,0,l){
        n1.push_back(s[i]-'0');
    }
    int i;
    for(i=0;i<k;i++){
        n2=n1;
        reverse(All(n2));
        if(n2==n1) break;
        vector<int>n3;
        int l=n1.size();
        n1.push_back(0);
        n2.push_back(0);
        repp(j,0,l){
            n1[j]+=n2[j];
            n3.push_back(n1[j]%10);
            n1[j+1]+=n1[j]/10;
        }
        if(n1[l]) n3.push_back(n1[l]);
        reverse(All(n3));
        n1=n3;
    }
    for(auto j:n1) cout<<j;
    cout<<endl;
    cout<<i<<endl;
}