//https://atcoder.jp/contests/code-festival-2014-quala/tasks/code_festival_qualA_c
//C - 2月29日
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

    auto count_leap_year = [](ll y){
        ll ret=y/4;
        ret -= (y/100);
        ret += (y/400);
        return ret;
    };
    ll ans= count_leap_year(B)-count_leap_year(A-1);
    cout<<ans<<endl;

    return 0;
}