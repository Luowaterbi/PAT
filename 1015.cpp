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
int n,d;
bool is_prime(int x){
    if(x==1||x==4) return 0;
    if(x==2||x==3) return 1;
    rep(i,2,sqrt(x))
        if(x%i==0) return 0;
    return 1;
}
int rever(){
    int num[100],len=0,res=0;
    while(n){
        num[++len]=n%d;
        n/=d;
    }
    rep(i,1,len){
        res=res*d+num[i];
    }
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    while(cin>>n&&n>=0){
        cin>>d;
        if(!is_prime(n)) cout<<"No"<<endl;
        else{
            cout<<(is_prime(rever())?"Yes":"No")<<endl;
        }    
    }
}