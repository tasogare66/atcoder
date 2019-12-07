//https://atcoder.jp/contests/ddcc2016-qual/tasks/ddcc_2016_qual_a
//
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
    double A,B,C; cin>>A>>B>>C;    
    auto u=C/A;
    auto ans=u*B;
    cout<<fixed<<std::setprecision(10)<<ans<<endl;
    return 0;
}