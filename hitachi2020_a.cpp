//https://atcoder.jp/contests/hitachi2020/tasks/hitachi2020_a
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
#if LOCAL&0
	std::ifstream in("./test/sample-1.in");
	//std::ifstream in("./input.txt");
	std::cin.rdbuf(in.rdbuf());
#else
	cin.tie(0);
	ios::sync_with_stdio(false);
#endif
	string S; cin>>S;
	string hi="hi";
	bool ans=true;
	if(S.size()%2!=0)ans=false;
	FOR(i,0,S.size()){
		if(S.at(i)!=hi.at(i%2))ans=false;
	}
	cout<<(ans?"Yes":"No")<<endl;
	return 0;
}