//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2199&lang=jp
//Differential Pulse Code Modulation
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
int solve(){
	ll N,M; cin>>N>>M;
	if (N==0&&M==0) return -1;
	vector<ll> cm(M);
	for(auto&& c:cm){
		cin>>c;
	}

	vector<int> xn(N);
	for(auto&& x:xn) cin>>x;

	constexpr ll INF=2LL<<60;
	vector<vector<ll>> dp(N+1,vector<ll>(256,INF));
	dp[0][128]=0;
	FOR(i,0,N){
		auto x=xn.at(i);
		FOR(v,0,256){ //FIXME:0->
			FOR(c,0,cm.size()){
				ll cv= cm.at(c);
				ll next_v=v+cv;
				if (next_v<0) next_v=0;
				if (next_v>=255) next_v=255;
				ll ad=(next_v-x);
				if (dp[i][v]<INF) chmin(dp[i+1][next_v],dp[i][v]+ad*ad);
			}
		}
	}

	ll ret=INF;
	FOR(v,0,256){
		chmin(ret,dp[N][v]);
	}

	return ret;
}
int main() {
#if LOCAL&01
	std::ifstream in("./test/sample-1.in");
	//std::ifstream in("./input.txt");
	std::cin.rdbuf(in.rdbuf());
#else
	cin.tie(0);
	ios::sync_with_stdio(false);
#endif
	while(true){
		ll r=solve();
		if(r<0)break;
		cout<<r<<endl;
	}
	return 0;
}