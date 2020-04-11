//https://atcoder.jp/contests/abc161/tasks/abc161_b
//B - Popular Vote
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
#if LOCAL&0
  std::ifstream in("./test/sample-3.in");
  //std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll N,M; cin>>N>>M;
  vector<ll> an(N);
  ll sums=0;
  for(auto&& a:an){
    cin>>a;
    sums += a;
  }
  ll lim=(sums+(4*M-1)) / (4*M);
  ll sel=0;
  for(const auto&a:an){
    if(a>=lim)++sel;
  }
  if(sel>=M)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;
}