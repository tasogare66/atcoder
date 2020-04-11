//https://atcoder.jp/contests/abc161/tasks/abc161_c
//C - Replacing Integer
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
  ll N, K; cin>>N>>K;
  ll tmp=N%K;
  ll tmp1=abs(tmp-K);
  ll ans=min(tmp,tmp1);
  cout<<ans<<endl;
  return 0;
}