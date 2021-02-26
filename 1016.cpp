#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repp(i,a,b) for(int i=(a);i<(b);i++)
#define lep(i,a,b) for(int i=(a);i>=(b);i--) 
#define lepp(i,a,b) for(int i=(a);i>(b);i--)
#define pss pair<string,string>
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
db money[30],pre[30];
map<string,int>peo;
int n;
struct people{
    string name;
    vector<pss>record;
    vector<pss>s_e;
    vector<pair<int,db> >t_m;
    db sum;
}per[N];
int get_num(string s,int p){
    return (s[p]-'0')*10+(s[p+1]-'0');
}
int cal(string s){
    return get_num(s,3)*24*60+get_num(s,6)*60+get_num(s,9);
}
bool cmp_time(const pss &A,const pss &B){
    return A.first<B.first;
}
bool cmp_name(const people &A,const people &B){
    return A.name<B.name;
}
db cal_money(string time1,string time2){
    int d1=get_num(time1,3),h1=get_num(time1,6),m1=get_num(time1,9);
    int d2=get_num(time2,3),h2=get_num(time2,6),m2=get_num(time2,9);
    db ans=0;
    if(d1!=d2){
        ans+=(d2-d1-1)*60*pre[23];
        ans+=(60-m1)*money[h1];
        ans+=60*(pre[23]-pre[h1]);
        if(h2!=0) ans+=60*pre[h2-1];
        ans+=m2*money[h2];
    }else{
        if(h1!=h2){
            ans+=(60-m1)*money[h1];
            ans+=60*(pre[h2-1]-pre[h1]);
            ans+=m2*money[h2];
        }else ans+=(m2-m1)*money[h1];
    }
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    repp(i,0,24){
        cin>>money[i];
        pre[i]+=pre[max(0,i-1)]+money[i];
    }   
    cin>>n;
    string s1,s2,s3;
    int cnt=0;
    rep(i,1,n){
        cin>>s1>>s2>>s3;
        if(peo.find(s1)==peo.end()){
            peo[s1]=++cnt;
            per[cnt].name=s1;
        }
        per[peo[s1]].record.push_back(mp(s2,s3));
    }
    sort(per+1,per+cnt+1,cmp_name);
    rep(i,1,cnt){
        sort(All(per[i].record),cmp_time);
        for(int j=1;j<per[i].record.size();j++){
            string time1=per[i].record[j-1].first,tag1=per[i].record[j-1].second;
            string time2=per[i].record[j].first,tag2=per[i].record[j].second;
            if(tag1=="on-line"&&tag2=="off-line"){
                per[i].s_e.push_back(mp(time1.substr(3),time2.substr(3)));
                per[i].t_m.push_back(mp(cal(time2)-cal(time1),cal_money(time1,time2)));
            }
        }
    }
    rep(i,1,cnt){
        if(per[i].s_e.size()==0) continue;
        cout<<per[i].name<<" "<<per[i].record[0].first.substr(0,2)<<endl;
        for(int j=0;j<per[i].s_e.size();j++){
            cout<<per[i].s_e[j].first<<" "<<per[i].s_e[j].second<<" ";
            cout<<per[i].t_m[j].first<<" $"<<fixed<<setprecision(2)<<per[i].t_m[j].second/100<<endl;
            per[i].sum+=per[i].t_m[j].second;
        }
        cout<<"Total amount: $"<<fixed<<setprecision(2)<<per[i].sum/100<<endl;
    }
}