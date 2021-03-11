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
map<string,vector<int> >stu;
int n,k,idx,m;
string name;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n>>k;
    rep(i,1,k){
        cin>>idx>>m;
        rep(j,1,m){
            cin>>name;
            stu[name].push_back(idx);
        }
    }
    rep(i,1,n){
        cin>>name;
        cout<<name<<" ";
        if(stu.find(name)==stu.end()){
            cout<<0<<endl;
            continue;
        }
        sort(All(stu[name]));
        cout<<stu[name].size();
        for(auto j:stu[name]) cout<<" "<<j;
        cout<<endl;
    }
}