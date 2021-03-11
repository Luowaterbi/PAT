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
vector<pair<string,string> >ans;
int n;
string id,pwd; 
bool find(string s,char c){return s.find(c)!=s.npos;}
string replace(string s){
    while(find(s,'1')){s.replace(s.find('1'),1,"@");}
    while(find(s,'0')){s.replace(s.find('0'),1,"%");}
    while(find(s,'l')){s.replace(s.find('l'),1,"L");}
    while(find(s,'O')){s.replace(s.find('O'),1,"o");}
    return s;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    cin>>n;
    rep(i,1,n){
        cin>>id>>pwd;
        if(find(pwd,'1')||find(pwd,'0')||find(pwd,'l')||find(pwd,'O')){
            ans.push_back(mp(id,replace(pwd)));
        }
    }
    if(ans.size()==0) cout<<"There "<<(n==1?"is ":"are ")<<n<<(n==1?" account":" accounts")<<" and no account is modified"<<endl;
    else{
        cout<<ans.size()<<endl;
        for(auto i:ans) cout<<i.first<<" "<<i.second<<endl; 
    }
}