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
int rel[2005][2005],t[2005],vis[2005],cnt=0,maxn=0,n,k,sum,sz,ans;
map<string,int>name;
string back[2005];
void dfs(int u){
    vis[u]=1;
    sz++;
    rep(i,1,cnt){
        t[u]+=rel[u][i];
        if(rel[u][i]==0||vis[i]) continue;
        dfs(i);
    }
    if(t[u]>maxn){
        maxn=t[u];
        ans=u;
    }
    sum+=t[u];
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n>>k;
    string a,b;
    int x;
    rep(i,1,n){
        cin>>a>>b>>x;
        if(name.find(a)==name.end()){
            name[a]=++cnt;
            back[cnt]=a;
        }
        if(name.find(b)==name.end()){
            name[b]=++cnt;
            back[cnt]=b;
        }
        rel[name[a]][name[b]]=rel[name[b]][name[a]]+=x;
    }
    vector<pair<string,int> >p;
    rep(i,1,cnt){
        if(vis[i]) continue;
        sum=maxn=sz=0;
        dfs(i);
        if(sz<=2||sum<=2*k) continue;
        p.push_back(mp(back[ans],sz));
    }
    cout<<p.size()<<endl;
    sort(All(p));
    for(auto i:p){
        cout<<i.first<<" "<<i.second<<endl;
    }
}