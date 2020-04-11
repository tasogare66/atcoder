//https://atcoder.jp/contests/abc106/tasks/abc106_d
//D - AtCoder Express 2
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
  ll N,M,Q; cin>>N>>M>>Q;
  vector<pair<ll,ll>> lrs(M);
  for(auto&& lr:lrs) cin>>lr.first>>lr.second;
  vector<pair<ll,ll>> querys(Q);
  for(auto&& q:querys) cin>>q.first>>q.second;
  //終端でsort
  //sort(lrs.begin(),lrs.end(),[](auto&a,auto&b){return a.second<b.second;});
  vector<vector<ll>> lsums(N+1,vector<ll>(N+1));//終端に応じた始点の累積和
  vector<ll> rsums(N+1);
  for(const auto& p:lrs){
    lsums[p.second][p.first]+=1;
    rsums[p.second]+=1;
  }
  FOR(i,1,N+1){
    rsums[i] += rsums[i-1];
  }

  FOR(i,1,N+1){
    FOR(t,1,N+1){
      lsums[t][i] += lsums[t-1][i];
    }
  }
  FOR(t,1,N+1){
    FOR(i,1,N+1){
      lsums[t][i] += lsums[t][i-1];
    }
  }

  for(const auto& qq:querys){
    ll p,q; tie(p,q)=qq;
    ll ans=rsums[q]-lsums[q][p-1];
    cout<<ans<<endl;
  }
#if 0
  vector<ll> lsums(N+1);
  vector<ll> rsums(N+1);
  REP(i,M){
    ll l,r; cin>>l>>r;
    ++lsums.at(l);
    ++rsums.at(r);
  }
  FOR(i,1,N+1){
    lsums[i] += lsums[i-1];
    rsums[i] += rsums[i-1];
  }
  dump(lsums);
  dump(rsums);
  REP(i,Q){
    ll p,q; cin>>p>>q;
    ll ans=rsums[q]-lsums[p-1];
    cout<<ans<<endl;
  }
#endif
  return 0;
}