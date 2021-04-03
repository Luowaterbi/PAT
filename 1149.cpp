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
const int N=1e6+5;
const int mod=1e9+7;
const db eps=1e-6;                                                                            
const db pi=acos(-1.0);
int n,m,k;
set<int>G;
set<int>s[N];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n>>m;
    int a,b;
    rep(i,1,n){
        cin>>a>>b;
        s[b].insert(a);
        s[a].insert(b);
    }
    rep(i,1,m){
        cin>>k;
        int flag=1;
        G.clear();
        rep(j,1,k){
            cin>>a;
            G.insert(a);
        }
        for(auto j:G){
            for(auto k:s[j]) if(G.find(k)!=G.end()){
                flag=0;
                break;
            }
            if(flag==0) break;
        }
        cout<<(flag?"Yes":"No")<<"\n";
    }
}