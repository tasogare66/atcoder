//https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_d
//D - パ研軍旗
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
	std::ifstream in("./test/sample-2.in");
	//std::ifstream in("./input.txt");
	std::cin.rdbuf(in.rdbuf());
#else
	cin.tie(0);
	ios::sync_with_stdio(false);
#endif
	ll N; cin>>N;
	vector<string> S5(5);
	for(auto&& s:S5){
		cin>>s;
	}
	constexpr ll INF=2LL<<60;
	vector<vector<ll>> dp(N+1,vector<ll>(3,INF));

	auto count = [&](ll p, char c){
		ll ret=0;
		for(const auto& s:S5){
			if(s.at(p)!=c) ++ret;
		}
		return ret;
	};

	char col[]={
		'R','B','W'
	};
	FOR(cur_c,0,3){
		ll i=0;
		dp[i][cur_c]=count(i,col[cur_c]);
	}
	FOR(i,0,N-1){
		FOR(cur_c,0,3){
			FOR(nex_c,0,3){//R,B,W
				if(cur_c==nex_c)continue;
				auto num=count(i+1,col[nex_c]);
				chmin(dp[i+1][nex_c], dp[i][cur_c]+num);
			}
		}
	}

	ll ans=INF;
	FOR(cur_c,0,3){
		chmin(ans,dp[N-1][cur_c]);
	}
	cout<<ans<<endl;

	return 0;
}