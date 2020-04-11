//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1611&lang=jp
//ダルマ落とし
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
#if 0
ll solve(){
  ll n; cin>>n;
  if(n==0) return -1;
  vector<ll> wn(n);
  for(auto&& w:wn) cin>>w;

  auto dfs = [&](auto&& self,ll l, ll r)->ll{
    ll ret=0;
    if(l+1>=r) return ret;
    FOR(k,l,r-1){
      if(abs(wn.at(k)-wn.at(k+1))>=2)continue;
      chmax(ret, self(self,l,k)+self(self,k+2,r)+2);
    }
    return ret;
  };

  ll ans=dfs(dfs, 0,n);
  cout<<ans<<endl;
  return ans;
}
#endif
ll solve2(){
  ll n; cin>>n;
  if(n==0) return -1;
  vector<ll> wn(n);
  for(auto&& w:wn) cin>>w;

  vector<vector<ll>> dp(n,vector<ll>(n+1));
  FOR(len,1,n){
    FOR(l,0,n){
      ll r=l+len;
      if (r>=n)break;
      if(len-1 == dp[l+1][r-1]){
        if (abs(wn.at(l)-wn.at(r))<2){
          dp[l][r] = dp[l+1][r-1]+2;
        } 
      }
      dump("-",len,l,r);
      //kで区切る
      for(ll k=l;k<r;++k){
        chmax(dp[l][r],dp[l][k]+dp[k+1][r]);
        dump(l,k,k+1,r,dp[l][r]);
      }
    }
  }
  dump(dp);
  ll ans=dp[0][n-1];
  cout<<ans<<endl;
  return ans;
}
int main() {
#if LOCAL&01
  //std::ifstream in("./test/sample-1.in");
  std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  while(solve2() >= 0){
    //break;
  }
  return 0;
}