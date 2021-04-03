#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define All(x) return (x).begin(),(x).end() 
using namespace std;
const int N=1e5+5;
int n,maxp,vis[N];
set<int>prime;
vector<int>p;
bool judge(int pos,int ap){
    int tmp=p[pos];
    rep(i,3,n){
        tmp+=ap;
        if(tmp>maxp||vis[tmp]==0) return 0;
    }
    return 1;
}
int main(){
    cin>>n>>maxp;
    rep(i,2,maxp){
        int flag=1;
        rep(j,2,sqrt(i)){
            if(i%j==0){
                flag=0;
                break;
            }
        }
        if(flag){
            vis[i]=1;
            p.push_back(i);
        }
    }
    int flag=0,st,ap=0,all=p.size();
    if(n==1){
        cout<<p[all-1];
        return 0;
    }else if(n==2){
        cout<<p[0]<<" "<<p[all-1];
        return 0;
    }
    rep(i,0,all-n){
        rep(j,i+1,all-n+1){            
            int tmp=p[j]-p[i];
            if(tmp<ap||tmp%2==1) continue;
            if(judge(j,tmp)){
                if(flag==0||tmp>=ap){
                    flag=1;
                    st=i;
                    ap=tmp;
                }
            }
        }
    }
    // cout<<"o"<<endl;
    if(flag){
        int tmp=p[st];
        rep(i,1,n){
            if(i==1) cout<<tmp;
            else cout<<" "<<tmp;
            tmp+=ap;
        }
    }else cout<<p[all-1];
}