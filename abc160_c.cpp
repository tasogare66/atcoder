//https://atcoder.jp/contests/abc160/tasks/abc160_c
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
#if LOCAL&01
  std::ifstream in("./test/sample-1.in");
  //std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll K,N; cin>>K>>N;
  vector<ll> an(N);
  for(auto&& a:an){
    cin>>a;
  }
  an.push_back(K+an.at(0));
  ll max_d=0;
  FOR(i,1,an.size()){
    ll d=an.at(i) - an.at(i-1);
    chmax(max_d,d);
  }
  ll ans=K-max_d;
  cout<<ans<<endl;
  return 0;
}