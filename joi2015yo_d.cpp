//https://atcoder.jp/contests/joi2015yo/tasks/joi2015yo_d
//D - シルクロード (Silk Road)
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
	ll N,M; cin>>N>>M;
	vector<ll> dn(N);
	for(auto&& d:dn) cin>>d;
	vector<ll> cm(M);
	for(auto&&c:cm) cin>>c;

	constexpr ll INF=2LL<<60LL;
	vector<vector<ll>> dp(N,vector<ll>(M,INF));
	FOR(c,0,cm.size()){
		ll v=cm.at(c) * dn.at(0);
		dp[0][c]=v;
		if (c-1>=0) dp[0][c]=min(dp[0][c],dp[0][c-1]);
	}

	FOR(d,0,dn.size()-1){
		FOR(c,0,cm.size()){
			if(c-1<0){
				dp[d+1][c]=INF;
			}else{
				ll v=cm.at(c) * dn.at(d+1);
				dp[d+1][c]=min(dp[d][c-1]+v,dp[d+1][c-1]);
			}
		}
	}
	dump(dp);
	ll ans=dp[N-1][M-1];
	cout<<ans<<endl;

	return 0;
}