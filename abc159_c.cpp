//https://atcoder.jp/contests/abc159/tasks/abc159_c
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
const ll LINF = 0x1fffffffffffffff;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
template<class T>bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1; } return 0;}
int main() {
  using ld=long double;
  ld L; cin>>L;
  ld tmp=L/3;
  ld ans = tmp*tmp*tmp;
  cout<<fixed<<std::setprecision(10)<<ans<<endl;
  return 0;
}