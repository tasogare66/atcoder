//https://atcoder.jp/contests/abc159/tasks/abc159_d
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
  ll N; cin>>N;
  vector<ll> an(N);
  unordered_map<ll,ll> tbl;
  for(auto&& a:an){
    cin>>a;
    tbl[a]++;
  }

  ll total=0;
  unordered_map<ll,ll> numtbl; //数字と通りのかず
  for(auto& m:tbl){
    ll n=m.second;
    ll tmp = n * (n-1) /2;
    total += tmp;
    numtbl[m.first] = tmp;
  }

  for(auto&& a: an){
    ll ans=total-numtbl[a];
    ll n =tbl[a]-1;
    ans += n * (n-1) /2;
    cout<<ans<<endl;
  }


  return 0;
}