//https://atcoder.jp/contests/pakencamp-2019-day4/tasks/pakencamp_2019_day4_b
//B - 情報の伝達
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
    std::ifstream in("./test/sample-3.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    ll prev=1;
    ll ans=1;
    FOR(i,0,N){
        prev = prev * 5;
        ans += prev;
        dump(i,ans);
    }
    cout<<ans<<endl;
    return 0;
}
