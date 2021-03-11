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

int viptable[105],n,m,k,cnt[105],table[N];
struct people{
    int time,server,vip,end;
}p[N];
deque<int>emp;
deque<people>q[2];

inline int get_num(string s,int pos){return (s[pos]-'0')*10+(s[pos+1]-'0');}
inline int cal_time(string s){return get_num(s,0)*3600+get_num(s,3)*60+get_num(s,6);}
bool cmp1(const people &A,const people &B){ return A.time<B.time;}
bool cmp_vip(const int &A,const int &B){
    if(viptable[A]!=viptable[B]) return viptable[A]>viptable[B];
    return A<B;
}
inline string add0(int num){return (num>=10?to_string(num):'0'+to_string(num));}
inline string back_time(int time){
    string s=add0(time%60);
    time/=60;
    string m=add0(time%60),h=add0(time/60);
    return h+':'+m+':'+s;
}
void work(int tmp,int time){
    int curt=emp.front();
    emp.pop_front();
    ++cnt[curt];
    people curp=q[tmp].front();
    q[tmp].pop_front();
    curp.end=time;
    table[curt]=time+curp.server;
    int wait=curp.end-curp.time;
    cout<<back_time(curp.time)<<" "<<back_time(curp.end)<<" ";
    cout<<wait/60+(wait%60>=30?1:0)<<endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n;
    rep(i,1,n){
        string s;
        cin>>s>>p[i].server>>p[i].vip;
        p[i].server=min(p[i].server,120);//手动更改必须2h
        p[i].server*=60;
        p[i].time=cal_time(s);
    }
    sort(p+1,p+n+1,cmp1);
    cin>>k>>m;
    rep(i,1,m){
        int x;
        cin>>x;
        viptable[x]=1;
    }
    int st_time=cal_time("08:00:00"),ed_time=cal_time("21:00:00");
    int head=1;
    rep(i,st_time,ed_time-1){
        while(head<=n&&p[head].time<=i) q[p[head].vip].push_back(p[head++]);//不能head>n就break，此时队列里还有人没分配到桌子
        if(!(q[0].size()+q[1].size())) continue;
        rep(j,1,k) if(table[j]<=i) emp.push_back(j);
        if(emp.size()==0) continue;
        if(q[1].size()){
            sort(All(emp),cmp_vip);
            while(q[1].size()&&emp.size()) 
                work(1,i);
        }
        if(emp.size()==0) continue;
        sort(All(emp));
        while(emp.size()&&q[0].size()){
            // int tmp;
            // if(q[0].size()&&q[1].size()) tmp=q[0].front().time>q[1].front().time?1:0;
            // else tmp=q[0].size()?0:1;
            work(0,i);
        }
        emp.clear();
    }

    rep(i,1,k){
        cout<<cnt[i];
        if(i!=k) cout<<" ";
    }
}