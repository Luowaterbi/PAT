#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repp(i,a,b) for(int i=(a);i<(b);i++)
#define lep(i,a,b) for(int i=(a);i>=(b);i--) 
#define lepp(i,a,b) for(int i=(a);i>(b);i--)
#define pii pair<int,int>
#define pll pair<long long,long long>
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
int n,m,rk[N][4];
string id[N],cl="ACME";
map<string,int>mp;
struct stu{
    int idx,c,m,e,a;
}s[N];
bool cmp1(const stu &A,const stu &B){
    return A.c>B.c;
}
bool cmp2(const stu &A,const stu &B){
    return A.m>B.m;
}
bool cmp3(const stu &A,const stu &B){
    return A.e>B.e;
}
bool cmp4(const stu &A,const stu &B){
    return A.a>B.a;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n>>m;
    rep(i,1,n){
        cin>>id[i];
        mp[id[i]]=i;
        cin>>s[i].c>>s[i].m>>s[i].e;
        s[i].a=(s[i].c+s[i].m+s[i].e)/3;
        s[i].idx=i;
    }
    sort(s+1,s+n+1,cmp1);
    rep(i,1,n){
        if(s[i].c==s[i-1].c) rk[s[i].idx][1]=rk[s[i-1].idx][1];
        else rk[s[i].idx][1]=i;
    }
    sort(s+1,s+n+1,cmp2);
    rep(i,1,n){
        if(s[i].m==s[i-1].m) rk[s[i].idx][2]=rk[s[i-1].idx][2];
        else rk[s[i].idx][2]=i;
    }
    sort(s+1,s+n+1,cmp3);
    rep(i,1,n){
        if(s[i].e==s[i-1].e) rk[s[i].idx][3]=rk[s[i-1].idx][3];
        else rk[s[i].idx][3]=i;
    }
    sort(s+1,s+n+1,cmp4);
    rep(i,1,n){
        if(s[i].a==s[i-1].a) rk[s[i].idx][0]=rk[s[i-1].idx][0];
        else rk[s[i].idx][0]=i;
    }
    
    string name;
    rep(i,1,m){
        cin>>name;
        if(mp.find(name)==mp.end()) cout<<"N/A"<<endl;
        else{
            int p=mp[name],best_rk=n+1,pos;
            rep(j,0,3) if(rk[p][j]<best_rk){
                best_rk=rk[p][j];
                pos=j;
            }
            cout<<best_rk<<" "<<cl[pos]<<endl;
        }
    }
}