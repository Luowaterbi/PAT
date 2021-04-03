#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define All(x) return (x).begin(),(x).end() 
using namespace std;
const int N=1e3+5;
int tr[N],n,m;
map<int,int>pos;
void up(int x){
    int p=x>>1;
    while(p){
        if(tr[p]<tr[x]){
            swap(tr[p],tr[x]);
            x=p;
        }else break;
        p=x>>1;
    }
}
int main(){
    cin>>n>>m;
    rep(i,1,n){
        cin>>tr[i];
        up(i);
    }
    rep(i,1,n) pos[tr[i]]=i;
    string opt,p;
    getchar();
    rep(i,1,m){
        int x,y;
        string a,b,c,d,e;
        getline(cin,opt);
        istringstream ss(opt);
        if(opt.find("root")!=opt.npos){
            ss>>x;
            cout<<(pos[x]==1?"1":"0");
        }else if(opt.find("siblings")!=opt.npos){
            ss>>x>>a>>y;
            cout<<(pos[x]/2==pos[y]/2?"1":"0");
        }else if(opt.find("parent")!=opt.npos){
            ss>>x>>a>>b>>c>>d>>y;
            cout<<(pos[y]/2==pos[x]?"1":"0");
        }else if(opt.find("left")!=opt.npos){
            ss>>x>>a>>b>>c>>d>>e>>y;
            cout<<(pos[x]==pos[y]*2?"1":"0");
        }else{
            ss>>x>>a>>b>>c>>d>>e>>y;
            cout<<(pos[x]==pos[y]*2+1?"1":"0");
        }
    }
}