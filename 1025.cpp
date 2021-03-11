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
struct node{
    string id;
    int sc,rank,part,finalrank;
    bool operator < (const node &A)const{
        if(sc==A.sc) return id<A.id;
        return sc>A.sc;
    }
}testee[N];
int n,k,l;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n;
    l=1;
    rep(j,1,n){
        cin>>k;
        rep(i,1,k){
            cin>>testee[l+i-1].id>>testee[l+i-1].sc;
            testee[l+i-1].part=j;
        }
        sort(testee+l,testee+l+k);
        testee[l].rank=1;
        rep(i,2,k){
            testee[i+l-1].rank=(testee[i+l-1].sc==testee[i+l-2].sc?testee[i+l-2].rank:i);
        }
        l+=k;
    }
    sort(testee+1,testee+l);
    testee[1].finalrank=1;//不加这个会WA3
    repp(i,2,l){
        testee[i].finalrank=(testee[i].sc==testee[i-1].sc?testee[i-1].finalrank:i);
    }
    cout<<l-1<<endl;
    repp(i,1,l){
        cout<<testee[i].id<<" "<<testee[i].finalrank<<" "<<testee[i].part<<" "<<testee[i].rank<<endl;
    }
}