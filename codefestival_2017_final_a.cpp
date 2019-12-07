//https://atcoder.jp/contests/cf17-final/tasks/cf17_final_a
//A - AKIBA
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
    string s; cin>>s;

    vector<string> chk;
    auto get=[&](vector<ll> um){
        string akb="AKIHABARA";
        string ret;
        ll pt=0;
        for(auto c:akb){
            if(c=='A'){
                if(um.at(pt++)) continue;
            }
            ret.push_back(c);
        }
        return ret;
    };
	REP(i, 2) {
		REP(j, 2) {
			REP(k, 2) {
				REP(l, 2) {
                   chk.emplace_back(get({i,j,k,l})); 
                }
			}
		}
	}

	for(const auto& t:chk){
        if(t==s) {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}