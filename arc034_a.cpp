//https://atcoder.jp/contests/arc034/tasks/arc034_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    vector<vector<ll>> tbl(N,vector<ll>(5));
    for(auto&& t:tbl){
        for(auto&& s:t){
            cin>>s;
        }
    }
    double ans=0;
    for(auto& t:tbl){
        double score=0.0;
        for(ll i=0;i<4;++i){
            score+=t[i];
        }
        score+=double(t[4])*110.0/900.0;
        ans=max(score,ans);
    }
    cout<<fixed<<std::setprecision(10)<<ans<<endl;
    return 0;
}