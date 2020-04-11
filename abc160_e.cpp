//https://atcoder.jp/contests/abc160/tasks/abc160_e
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
  ll X,Y,A,B,C; cin>>X>>Y>>A>>B>>C;
  vector<ll> pa(A); for(auto&&p:pa) cin>>p;
  vector<ll> qb(B); for(auto&&q:qb) cin>>q;
  vector<ll> rc(C); for(auto&&r:rc) cin>>r;
  sort(pa.begin(),pa.end(),greater<ll>());
  sort(qb.begin(),qb.end(),greater<ll>());
  sort(rc.begin(),rc.end(),greater<ll>());

  vector<ll> ren;
  FOR(i,0,min<ll>(X,pa.size())){
    ren.push_back(pa.at(i));
  }
  FOR(i,0,min<ll>(Y,qb.size())){
    ren.push_back(qb.at(i));
  }
  ren.insert(ren.end(),rc.begin(),rc.end());
  sort(ren.begin(),ren.end(),greater<ll>());
  ll ans=0;
  FOR(i,0,X+Y){
    ans+=ren.at(i);
  }
  cout<<ans<<endl;

  return 0;
}