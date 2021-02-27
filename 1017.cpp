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
int n,k;
int get_num(string s,int p){
    return (s[p]-'0')*10+(s[p+1]-'0');
}
int cal_time(string s){
    return get_num(s,0)*60*60+get_num(s,3)*60+get_num(s,6);
}
struct peo{
    int time,p;
    bool operator < (const peo &A)const{
        return time<A.time;
    }
};
vector<peo>people;
priority_queue<int>window;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n>>k;
    rep(i,1,n){
        string s;
        int p;
        cin>>s>>p;
        if(s>"17:00:00") continue;
        people.push_back({cal_time(s),p});
    }
    sort(All(people));
    rep(i,1,k) window.push(-cal_time("08:00:00"));
    db sum=0,cnt=0;
    for(auto cur:people){
        int cur_time=-window.top();
        window.pop();
        if(cur_time>cur.time){
            sum+=cur_time-cur.time;
            cur_time+=cur.p*60;
        }else cur_time=cur.time+cur.p*60;
        cnt+=1;
        window.push(-cur_time);
    }
    cout<<fixed<<setprecision(1)<<sum/60/cnt<<endl;
}