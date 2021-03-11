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
pair<db,db>sta[505];
db c,d,avg;
int n;
db cost[505];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>c>>d>>avg>>n;
    rep(i,1,n) cin>>sta[i].second>>sta[i].first;
    sort(sta+1,sta+n+1);
    n++;
    sta[n].first=d;
    sta[n].second=0;
    if(sta[1].first!=0){
        cout<<"The maximum travel distance = 0.00"<<endl;
        return 0;
    }
    db cost=0,cur_gas=0;
    int minn; 
    for(int i=1;i<n;i=minn){
        db X=sta[i].first+c*avg;
        if(X<sta[i+1].first){
            cout<<"The maximum travel distance = "<<fixed<<setprecision(2)<<X<<endl;
            return 0;
        }
        minn=i+1;
        for(int j=i+1;j<=n&&sta[j].first-sta[i].first<=c*avg;++j){
            if(sta[j].second<sta[i].second){
                minn=j;
                break;
            }else if(sta[j].second<sta[minn].second) minn=j;
        }
        if(sta[minn].second<=sta[i].second){
            cost+=sta[i].second*((sta[minn].first-sta[i].first)/avg-cur_gas);
            cur_gas=0;
        }else{
            cost+=sta[i].second*(c-cur_gas);
            cur_gas=c-(sta[minn].first-sta[i].first)/avg;
        }
    }
    cout<<fixed<<setprecision(2)<<cost<<endl;
}