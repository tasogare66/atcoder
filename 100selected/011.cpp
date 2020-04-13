//https://atcoder.jp/contests/abc128/tasks/abc128_c
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
  ll N,M; cin>>N>>M;
  vector<ll> smm(M);
  vector<ll> pm(M);

  FOR(i,0,M){
    ll k; cin>>k;
    ll msk=0;
    REP(j,k){
      ll s; cin>>s; --s;
      msk |= 1LL<<s;
      smm.at(i)=msk;
    }
  }
  for(auto&& p:pm){
    cin>>p;
  }

  ll ans=0;
  ll bit_max=1LL<<N;
  FOR(b,0,bit_max){
    bool flag=true;
    FOR(i,0,M){
      ll msk = b&smm.at(i);
      ll n = __builtin_popcount(msk) % 2;
      if(pm.at(i)!=n) {
        flag=false;
        break;
      }
    }
    if(flag)++ans;
  }
  cout<<ans<<endl;
  return 0;
}