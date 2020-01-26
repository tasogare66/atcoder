//https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_a
//A - パ研合宿2103
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
    ll A,B; cin>>A>>B;
    auto ans = B-A+1;
    cout<<ans<<endl;    
    return 0;
}