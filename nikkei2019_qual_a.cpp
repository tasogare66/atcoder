//https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_a
//A - Subscribers
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
    ll N, A, B; cin>>N>>A>>B;    
    ll ans0 = min(A,B);
    ll ans1 = max(0LL, A+B-N);
    cout<<ans0<<" "<<ans1<<endl;
    return 0;
}