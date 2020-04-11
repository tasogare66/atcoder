//https://atcoder.jp/contests/abc160/tasks/abc160_b
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
  ll X; cin>>X;
  ll ans=0;
  ll num=X/500;
  ans += num*1000;
  ll xx=X-500*num;
  ans += (xx/5)*5;
  cout<<ans<<endl;
  return 0;
}