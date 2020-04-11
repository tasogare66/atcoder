//https://atcoder.jp/contests/joi2015ho/tasks/joi2015ho_a
//A - 鉄道旅行 (Railroad Trip)
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
  vector<ll> pm(M);
  for(auto&& p:pm) cin>>p;
  vector<tuple<ll,ll,ll>> abcn(N+1);
  FOR(i,1,N+1){
    auto&& t=abcn.at(i);
    cin>>get<0>(t)>>get<1>(t)>>get<2>(t);
  }
  vector<ll> cnt(N+1);
  FOR(i,1,M){
    ll st=pm.at(i-1);
    ll ed=pm.at(i);
    if(st>ed) swap(st,ed);
    cnt.at(st)++;
    cnt.at(ed)--;
  }
  ll ans=0;
  ll num=0;
  FOR(i,1,N+1){
    num += cnt.at(i);
    ll a,b,c; tie(a,b,c)=abcn.at(i);
    ans += min(a*num, b*num+c);
  }
  cout<<ans<<endl;

  return 0;
}