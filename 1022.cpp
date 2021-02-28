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
map<string,vector<string> >title,author,keyword,publisher,year;
int n,m;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    string id,t,a,k,p,y;
    cin>>n;
    getline(cin,id);//cin之后getline一下，否则会读到换行符
    rep(i,1,n){
        getline(cin,id);
        getline(cin,t);
        title[t].push_back(id);
        getline(cin,a);
        author[a].push_back(id);
        getline(cin,k);
        istringstream kk(k);
        string kw;
        while(kk>>kw){
            keyword[kw].push_back(id);
        }
        getline(cin,p);
        publisher[p].push_back(id);
        getline(cin,y);
        year[y].push_back(id);
    }
    cin>>m;
    string q;
    getline(cin,q);
    rep(i,1,m){
        getline(cin,q);
        cout<<q<<endl;
        string message=q.substr(q.find(' ')+1);
        vector<string>ans;
        switch (q[0]){
        case '1':
            ans=title[message];
            break;
        case '2':
            ans=author[message];
            break;
        case '3':
            ans=keyword[message];
            break;
        case '4':
            ans=publisher[message];
            break;
        case '5':
            ans=year[message];
            break;
        default:
            break;
        } 
        if(ans.size()==0) cout<<"Not Found"<<endl;
        else{
            sort(All(ans));
            for(auto i:ans) cout<<i<<endl;
        }
        
    }
}