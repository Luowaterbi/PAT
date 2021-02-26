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
const int N=1e3+5;
const int mod=1e9+7;
const db eps=1e-6;                                                                            
const db pi=acos(-1.0);
queue<int>q[25];
int need_t[N],ans[N],n,m,k,Q;
void print(int x){
    if(x==0) cout<<"Sorry"<<endl;
    else{
        int h=8+x/60,m=x%60;
        if(h<10) cout<<0<<h;
        else cout<<h;
        cout<<":";
        if(m<10) cout<<0<<m;
        else cout<<m;
        cout<<endl;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n>>m>>k>>Q;
    rep(i,1,k) cin>>need_t[i];
    int cur=0,head[25],cnt=1;
    rep(j,1,m)
        rep(i,1,n) 
            if(cnt<=k) q[i].push(cnt++);
    rep(i,1,n)
        if(q[i].size()) 
            head[i]=need_t[q[i].front()];    
    while(cur<540){
        ++cur;
        rep(i,1,n){
            if(q[i].size()){
                --head[i];
                if(head[i]==0){
                    ans[q[i].front()]=cur;
                    q[i].pop();
                    if(cnt<=k) q[i].push(cnt++);
                    if(q[i].size()) head[i]=need_t[q[i].front()];
                }
            }
        }
    }
    rep(i,1,n) if(q[i].size()){
        if(head[i]!=need_t[q[i].front()]) ans[q[i].front()]=540+head[i];
    }
    int x;
    rep(i,1,Q){
        cin>>x;
        print(ans[x]);
    }
}