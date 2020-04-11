//https://atcoder.jp/contests/dp/tasks/dp_n
//N - Slimes
//区間dp,O(N^3)
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
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
  ll N; cin>>N;
  vector<ll> an(N);
  for(auto&& a:an){
    cin>>a;
  }
  vector<ll> sums(N+1);
  FOR(i,0,N){
    sums[i+1]=sums[i]+an.at(i);
  }
  auto sum=[&](ll l, ll r){
    return sums[r]-sums[l];
  };
  dump(sum(0,N));
#if 1
  //forで回す
  constexpr ll INF=2LL<<60;
  vector<vector<ll>> dp(N,vector<ll>(N+1,INF));
  //初期値
  FOR(i,0,N){
    dp[i][i+1]=0;
  }
  FOR(len,2,N+1){
    for(ll l=0;l+len<=N;++l){
      ll r = l+len;
      for(ll k=l+1;k<r;++k){
        dump(l,k,r);
        chmin(dp[l][r],dp[l][k]+dp[k][r]+sum(l,r));
      }
    }    
  }
  dump(dp);
  cout<<dp[0][N]<<endl;
#else
  //メモ化再帰
  //開区間
  vector<vector<ll>> dp(N,vector<ll>(N+1,INT64_MAX));
  function<ll(ll,ll)> dfs=[&](ll l, ll r)->ll{
    if(l+1>=r)return 0;
    if(dp.at(l).at(r)!=INT64_MAX) return dp[l][r];
    ll ret=INT64_MAX;
    FOR(k,l+1,r){
      chmin(ret,dfs(l,k)+dfs(k,r)+sum(l,r));
    }
    dp.at(l).at(r)=ret;
    return ret;
  };
  auto ans=dfs(0,N);
  cout<<ans<<endl;
#endif
  return 0;
}