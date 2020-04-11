//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1167&lang=jp
//Pollock's conjecture
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
ll calc_vol(ll n){
	return n*(n+1)*(n+2)/6;
}
constexpr ll INF=2LL<<60;

int main(){
#if LOCAL&01
	std::ifstream in("./test/sample-1.in");
	//std::ifstream in("./input.txt");
	std::cin.rdbuf(in.rdbuf());
#else
	cin.tie(0);
	ios::sync_with_stdio(false);
#endif

	ll val=1e+6;
	ll limit=1;
	vector<ll> vols0(2),vols1(2);
	vols0[0]=0; vols1[0]=0;
	vols0[1]=1; vols1[1]=1;
	while(calc_vol(limit+1)<=val){
		auto v=calc_vol(limit+1);
		vols0.push_back(v);
		if(v%2==1)vols1.push_back(v);
		limit++;
	}

	auto mktbl = [&val](vector<ll>& dp, const auto& vols){
		dp[0]=0;
		ll lim = vols.size()-1;
		FOR(i,0,lim){
			ll vol=vols.at(i+1);
			dump(vol);
			FOR(j,0,val+1){
				if(j-vol>=0)chmin(dp[j],dp[j-vol]+1);
			}
		}
	};
	vector<ll> dp0(val+1,INF);
	mktbl(dp0,vols0);

	vector<ll> dp1(val+1,INF);
	mktbl(dp1,vols1);

	while(true){
		ll t; cin>>t;
		if(t==0)break;
		cout<<dp0[t]<<" "<<dp1[t]<<endl;
	}

	return 0;
}
#if 0
ll solve(const ll val){
	ll limit=1;
	while(calc_vol(limit+1)<=val){
		limit++;
	}
	dump(limit,calc_vol(limit));

	vector<ll> dp(val+1,INF);
	dp[0]=0;
	FOR(i,0,limit+1){
		ll vol=calc_vol(i+1);
		FOR(j,0,val+1){
			//chmin(dp[i+1][j],dp[i][j]);
			if(j-vol>=0)chmin(dp[j],dp[j-vol]+1);
			//if(j-vol>=0)chmin(dp[j],dp[j-vol]+1);
		}
	}
	dump(dp);

	return dp[val];
}
ll solve2(const ll val){
	ll limit=1;
	vector<ll> vols(2);
	vols[0]=0;
	vols[1]=1;
	while(calc_vol(limit+1)<=val){
		auto v=calc_vol(limit+1);
		if(v%2==1)vols.push_back(v);
		limit++;
	}
	dump(limit,calc_vol(limit));

	vector<ll> dp(val+1,INF);
	dp[0]=0;
	limit = vols.size()-1;
	FOR(i,0,limit){
		//ll n2=lim2i(i);
		//ll vol=calc_vol(n2);
		ll vol=vols.at(i+1);
		dump(vol);
		FOR(j,0,val+1){
			//chmin(dp[i+1][j],dp[i][j]);
			if(j-vol>=0)chmin(dp[j],dp[j-vol]+1);
			//if(j-vol>=0)chmin(dp[j],dp[j-vol]+1);
		}
	}
	dump(dp);

	return dp[val];
}
int main_() {
#if LOCAL&01
	std::ifstream in("./test/sample-1.in");
	//std::ifstream in("./input.txt");
	std::cin.rdbuf(in.rdbuf());
#else
	cin.tie(0);
	ios::sync_with_stdio(false);
#endif
	//solve2(40); return 0;
	while(true){
		ll t; cin>>t;
		if(t==0)break;
		cout<<solve(t)<<" "<<solve2(t)<<endl;
	}
	return 0;
}
#endif