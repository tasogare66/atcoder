//https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_b
//B - Bishop
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
  ll H,W; cin>>H>>W;
#if 01
  ll ans=(H*W+1)/2;
  if(H==1||W==1) ans=1;
  cout<<ans<<endl;
#else
  ll x0=(H+1)/2;
  ll x1=(H)/2;
  ll y0=(W+1)/2;
  ll y1=(W)/2;  
  ll ans=x0*y0+x1*y1;
  if(H==1||W==1) ans=1;
  cout<<ans<<endl;
#endif
  return 0;
}