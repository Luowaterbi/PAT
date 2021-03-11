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
struct stu{
    string name,ID;
    int grade;
    bool operator < (const stu &A)const{
        return grade<A.grade;
    }
};
// vector<stu>boy,girl;
int n;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n;
    stu cur,boy,girl;
    char gender;
    boy.grade=girl.grade=-1;
    rep(i,1,n){
        cin>>cur.name>>gender>>cur.ID>>cur.grade;
        if(gender=='M'){
            if(boy.grade==-1||boy.grade>cur.grade) boy=cur;
        }else{
            if(girl.grade==-1||girl.grade<cur.grade) girl=cur;
        }
    }
    int last=(girl.grade==-1||boy.grade==-1?INF:girl.grade-boy.grade);
    if(girl.grade==-1) cout<<"Absent"<<endl;
    else cout<<girl.name<<" "<<girl.ID<<endl;
    if(boy.grade==-1) cout<<"Absent"<<endl;
    else cout<<boy.name<<" "<<boy.ID<<endl;
    cout<<(last==INF?"NA":to_string(last))<<endl;
}