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
int k,nxt[N];
string ans[60];
int dfs(int pos,int d){
    int res=pos;
    rep(i,1,d) 
        res=nxt[res];
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>k;
    int x;
    rep(i,1,54){
        cin>>x;
        nxt[i]=x;
    }
    string s="SHCD";
    rep(i,0,3){
        rep(j,1,13)
            ans[dfs(i*13+j,k)]=s[i]+to_string(j);
    }
    ans[dfs(53,k)]="J1";
    ans[dfs(54,k)]="J2";
    rep(i,1,54){
        if(i==1) cout<<ans[i];
        else cout<<" "<<ans[i];
    }
}