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
vector<vector<string> >ex;
int n,k;
bool cmp0(const vector<string>&A,vector<string>&B){return A[0]<B[0];}
bool cmp1(const vector<string>&A,vector<string>&B){
    if(A[1]==B[1]) return cmp0;
    return A[1]<B[1];
}
bool cmp2(const vector<string>&A,vector<string>&B){
    if(A[2]==B[2]) return cmp0;
    return A[2]<B[2];
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n>>k;
    rep(i,1,n){
        vector<string>st(3);
        cin>>st[0]>>st[1]>>st[2];
        ex.push_back(st);
    }
    if(k==1) sort(All(ex),cmp0);
    else if(k==2) sort(All(ex),cmp1);
    else sort(All(ex),cmp2);
    for(auto st:ex){
        cout<<st[0]<<" "<<st[1]<<" "<<st[2]<<endl;
    }
}