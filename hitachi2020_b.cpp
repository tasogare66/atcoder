//https://atcoder.jp/contests/hitachi2020/tasks/hitachi2020_b
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
	ll A,B,M; cin>>A>>B>>M;
	vector<ll> aA(A);
	ll min_a=INT64_MAX;
	ll min_b=INT64_MAX;
	for(auto&& a:aA) {
		cin>>a;
		chmin(min_a,a);
	}
	vector<ll> bB(B);
	for(auto&& b:bB) {
		cin>>b;
		chmin(min_b,b);
	}

	ll ans=min_a+min_b;
	FOR(i,0,M){
		ll x,y,c; cin>>x>>y>>c;
		--x;--y;
		ll v=aA.at(x)+bB.at(y)-c;
		chmin(ans,v);
	}
	cout<<ans<<endl;

	return 0;
}