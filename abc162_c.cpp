//https://atcoder.jp/contests/abc162/tasks/abc162_c
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
  ll K; cin>>K;
  ll ans=0;
  FOR(a,1,K+1){
    FOR(b,1,K+1){
      ll t=std::gcd(a,b);
      FOR(c,1,K+1){
        ans += std::gcd(t,c);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}