//https://atcoder.jp/contests/arc091/tasks/arc091_b
//D - Remainder Reminder
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
template<class T>bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1; } return 0;}
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,K; cin>>N>>K;
    ll ans=0;
    for(ll b=K+1;b<=N;++b){
        ll as=K;
        ll at=b-1;
        auto u = (at-as+1);
        auto m = N/b;
        ans += u*m;
    }
    cout<<ans<<endl;
    return 0;
}