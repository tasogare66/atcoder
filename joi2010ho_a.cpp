//https://atcoder.jp/contests/joi2010ho/tasks/joi2010ho_a
//A - 旅人
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

constexpr ll MOD=100000;

int main() {
#if LOCAL&01
  //std::ifstream in("./test/sample-1.in");
  std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll n,m; cin>>n>>m;
  vector<ll> sn(n);
  vector<ll> an(m);
  FOR(i,1,n){
    cin>>sn.at(i);
  }
  for(auto&& a:an) cin>>a;

  vector<ll> sums(n+1);
  FOR(i,1,n){
    sums[i]=sn.at(i)+sums[i-1];
  }
  dump(sums);
  auto dist = [&](ll is, ll ie){
    if(is>ie) swap(is,ie);
    return sums[ie-1] - sums[is-1];
  };
  dump(dist(7,1));

  ll pt=1;
  ll ans=0;
  for(const auto& a:an){
    ll st=pt;
    ll ed=pt + a;
    dump(st,ed,a);
    pt = ed;
    if(st>ed) swap(st,ed);
    ans += sums[ed-1] - sums[st-1];
    ans %= MOD;
    dump(ans);
  }
  cout<<ans<<endl;

  return 0;
}