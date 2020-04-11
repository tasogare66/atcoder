//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_B&lang=ja
//Matrix Chain Multiplication
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
	//std::ifstream in("./test/sample-1.in");
	std::ifstream in("./input.txt");
	std::cin.rdbuf(in.rdbuf());
#else
	cin.tie(0);
	ios::sync_with_stdio(false);
#endif
  ll n; cin>>n;
  vector<pair<ll,ll>> rcn(n);
  for(auto&& rc:rcn){
   cin>>rc.first>>rc.second;
  }
	vector<vector<ll>> dp(n,vector<ll>(n+1,-1));
  auto dfs = [&](auto&& self, ll l, ll r)->ll{
    if(l+1>=r)return 0;
		if(dp[l][r]>=0)return dp[l][r];
    ll ret=INT64_MAX;
    FOR(k,l+1,r){
      ll mulnum = rcn.at(l).first * rcn.at(k).first * rcn.at(r-1).second;
      chmin(ret, self(self,l,k)+self(self,k,r) + mulnum);
    }
		dump(l,r,ret);
		dp[l][r]=ret;
    return ret;
  };

	ll ans=dfs(dfs,0,n);
	cout<<ans<<endl;

  return 0;
}