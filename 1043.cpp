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
int n,pre[1005],lc[1005],rc[1005];
bool test1(int l,int r){
    if(l>=r) return 1;
    int pos;
    for(pos=l+1;pos<=r&&pre[pos]<pre[l];++pos);
    rep(i,pos,r) if(pre[i]<pre[l]) return 0;
    if(pre[l+1]<pre[l]) lc[l]=l+1;
    if(pos<=r) rc[l]=pos;
    return test1(l+1,pos-1)&&test1(pos,r);
}
bool test2(int l,int r){
    if(l>=r) return 1;
    int pos;
    for(pos=l+1;pos<=r&&pre[pos]>=pre[l];++pos);
    rep(i,pos,r) if(pre[i]>=pre[l]) return 0;
    if(pre[l+1]>=pre[l]) lc[l]=l+1;
    if(pos<=r) rc[l]=pos;
    return test2(l+1,pos-1)&&test2(pos,r);
} 
vector<int>ans;
void dfs(int u){
    if(lc[u]) dfs(lc[u]);
    if(rc[u]) dfs(rc[u]);
    ans.push_back(pre[u]);
}
int mark=0;
void print(int opt){
    if(opt==2) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        dfs(1);
        repp(i,0,n){
            if(i==0) cout<<ans[i];
            else cout<<" "<<ans[i];
        }
    }
    mark=1;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n;
    rep(i,1,n) cin>>pre[i];
    if(n!=1){
        if(!test1(1,n)){
            ms(lc,0),ms(rc,0);
            if(!test2(1,n)) print(2);
        }
    }
    if(mark==0) print(1);
}