//https://atcoder.jp/contests/abc161/tasks/abc161_a
//A - ABC Swap
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
  ll X,Y,Z; cin>>X>>Y>>Z;
  swap(X,Y);
  swap(X,Z);
  cout<<X<<" "<<Y<<" "<<Z<<endl;
  return 0;
}