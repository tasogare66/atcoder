//https://atcoder.jp/contests/judge-update-202004/tasks/judge_update_202004_a
//A - Walking Takahashi
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
  ll S,L,R; cin>>S>>L>>R;
  if (S<=L) cout<<L<<endl;
  else if(S>=R) cout<<R<<endl;
  else cout<<S<<endl;
  return 0;
}