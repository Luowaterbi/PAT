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
string n1,n2;
int tag,radix;
ll num1,num2;
int change(char c){
    if(c>='0'&&c<='9') return c-'0';
    return c-'a'+10;
}
ll cal(string s,int r){
    int l=s.size();
    ll res=0;
    repp(i,0,l){
        res=res*r+change(s[i]);
    }
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n1>>n2>>tag>>radix;
    if(tag==2) swap(n1,n2);
    num1=cal(n1,radix);
    int l2=n2.size(),minn=0;
    repp(i,0,l2){
        minn=max(minn,change(n2[i]));
    }
    ll l=minn+1,r=max(l,num1);
    while(l<r){
        ll mid=(l+r)>>1;
        num2=cal(n2,mid);
        if(num2<0||num2>=num1) r=mid;
        else l=mid+1;
    }
    if(cal(n2,l)==num1) cout<<l<<endl;
    else cout<<"Impossible"<<endl;
}