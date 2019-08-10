//https://atcoder.jp/contests/arc005/tasks/arc005_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    ll ans=0;
    REP(i,N){
        string w; cin>>w;
        if(w.back()=='.'){
            w.erase(w.size()-1);
        }
        if(w=="TAKAHASHIKUN"||w=="Takahashikun"||w=="takahashikun"){
            ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}