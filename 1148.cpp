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
const int N=100+5;
const int mod=1e9+7;
const db eps=1e-6;                                                                            
const db pi=acos(-1.0);
int n,p[N],w[N];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n;
    rep(i,1,n) cin>>p[i];
    rep(i,1,n)
        rep(j,i+1,n){
            vector<int>liar;
            liar.clear();
            fill(w+1,w+n+1,1);
            w[i]=w[j]=-1;
            rep(k,1,n)
                if(p[k]*w[abs(p[k])]<0) liar.push_back(k);
            if(liar.size()==2&&w[liar[0]]+w[liar[1]]==0){
                cout<<i<<" "<<j<<"\n";
                return 0;
            }
        }
    cout<<"No Solution\n";
}