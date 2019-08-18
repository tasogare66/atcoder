//https://atcoder.jp/contests/abc138/tasks/abc138_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<double> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    double sum0=0.0;
    for(const auto& a:an){
        sum0 += 1.0/a;
    }
    double ans = 1.0/sum0;
    cout<<fixed<<std::setprecision(10)<<ans<<endl;
    return 0;
}