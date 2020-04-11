//https://atcoder.jp/contests/abc158/tasks/abc158_d
//D - String Formation
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
	string S; cin>>S;
	ll Q; cin>>Q;
	deque<char> lst;
	for(auto& c:S){
		lst.push_back(c);
	}

	bool swf=false;
	REP(i,Q){
		ll t; cin>>t;
		if(t==1){
			swf=!swf;
		}else{
			ll fb; cin>>fb;
			char c; cin>>c;
			if(swf) {
				fb = (fb==1)?2:1;
			}
			if(fb==1){
				lst.push_front(c);
			}else{
				lst.push_back(c);
			}
		}
	}
	if(swf){
		reverse(lst.begin(),lst.end());
	}

	for(const auto&c:lst){
		cout<<c;
	}
	cout<<endl;

	return 0;
}