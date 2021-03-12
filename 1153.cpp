#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repp(i,a,b) for(int i=(a);i<(b);i++)
#define lep(i,a,b) for(int i=(a);i>=(b);i--) 
#define lepp(i,a,b) for(int i=(a);i>(b);i--)
#define psi pair<string,int>
#define pii pair<int,int>
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
map<char,vector<psi> >level;
map<string,pii>site;
map<string,vector<string> >date;
bool cmp(const psi &A,const psi &B){
    if(A.second==B.second) return A.first<B.first;
    return A.second>B.second; 
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("D:\\work\\data.in","r",stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    rep(i,1,n){
        psi stu;
        cin>>stu.first>>stu.second;
        char curlevel=stu.first[0];
        string cursite=stu.first.substr(1,3),curdate=stu.first.substr(4,6);
        level[curlevel].push_back(stu);
        ++site[cursite].first;
        site[cursite].second+=stu.second;
        date[curdate].push_back(cursite);
    }
    int opt;
    string ord;
    rep(i,1,m){
        cin>>opt>>ord;
        cout<<"Case "<<i<<": "<<opt<<" "<<ord<<"\n";
        if(opt==1){
            if(level.find(ord[0])==level.end()){
                cout<<"NA"<<"\n";
                continue;
            }
            sort(All(level[ord[0]]),cmp);
            for(auto stu:level[ord[0]]) cout<<stu.first<<" "<<stu.second<<"\n";
        }else if(opt==2){
            if(site.find(ord)==site.end()){
                cout<<"NA"<<"\n";
                continue;
            }
            cout<<site[ord].first<<" "<<site[ord].second<<"\n";
        }else{
            if(date.find(ord)==date.end()){
                cout<<"NA"<<"\n";
                continue;
            }
            vector<psi>ans;
            map<string,int>cnt;
            for(auto s:date[ord]) ++cnt[s];
            for(auto s:cnt) ans.push_back(mp(s.first,s.second));
            sort(All(ans),cmp);
            for(auto s:ans) cout<<s.first<<" "<<s.second<<"\n";
        }
    }
}