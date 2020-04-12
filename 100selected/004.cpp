//https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_c
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
  ll N,M; cin>>N>>M;
  vector<vector<ll>> anm(N+1,vector<ll>(M+1));
  FOR(i,1,N+1){
    FOR(j,1,M+1){
      cin>>anm.at(i).at(j);
    }
  }
  ll ans=0;
  FOR(t1,1,M+1){
    FOR(t2,t1+1,M+1){
      ll sc=0;
      FOR(i,1,N+1){
        sc += max(anm.at(i).at(t1), anm.at(i).at(t2));
      }
      chmax(ans,sc);
    }
  }
  cout<<ans<<endl;
  return 0;
}