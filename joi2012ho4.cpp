//https://atcoder.jp/contests/joi2012ho/tasks/joi2012ho4
//D - 釘 (Nails)
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
  //std::ifstream in("./test/sample-1.in");
  std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll N, M; cin>>N>>M;
  ll total = (N+1)*N/2;
  vector<ll> cnt(total+1);

  auto pos2id=[](ll ia, ll ib){
    return ia*(ia-1)/2+ib;
  };

  REP(i,M){
    ll A,B,X; cin>>A>>B>>X;
    auto p=pos2id(A,B);
    chmax(cnt.at(p), X+1);
  }

  FOR(y,1,N+1){
    FOR(x,1,y+1){
      auto p = pos2id(y,x);
      auto c = max<ll>(cnt.at(p)-1,0);
      if(y+1>N) continue;
      auto p0 = pos2id(y+1,x);
      chmax(cnt.at(p0),c);
      auto p1 = p0+1; //pos2id(y+1,x+1);
      chmax(cnt.at(p1),c); 
    }
  }

  ll ans=0;
  for(const auto& c:cnt){
    if(c>0) ++ans;
  }
  cout<<ans<<endl;

  return 0;
}