//https://atcoder.jp/contests/ddcc2017-qual/tasks/ddcc2017_qual_b
//B - 鉛筆
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
    ll A,B,C,D; cin>>A>>B>>C>>D;    
    ll ans=0;
    ans += A*1728;
    ans += B*144;
    ans += C*12;
    ans += D;
    cout<<ans<<endl;
    return 0;
}