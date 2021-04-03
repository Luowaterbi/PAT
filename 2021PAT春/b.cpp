#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define All(x) (x).begin(),(x).end() 
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int N=1e5+5;
int n,c[N];
int get_num(string s,int pos){
    return (s[pos]-'0')*10+(s[pos+1]-'0');
}
int cal_time(string s){
    return get_num(s,0)*3600+get_num(s,3)*60+get_num(s,6);
}
vector<pii>stu;
int main(){
    cin>>n;
    string st,ed;
    rep(i,0,n-1){
        cin>>st>>ed;
        stu.push_back(mp(cal_time(st),cal_time(ed)));
        c[i]=1;
    }
    sort(All(stu));
    int maxn=0;
    for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            if(stu[j].second<=stu[i].first){
                c[j]=max(c[j],1+c[i]);
            }
        }
        maxn=max(maxn,c[i]);
    }
    cout<<maxn<<endl;
    
}