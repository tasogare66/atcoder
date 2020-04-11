//https://atcoder.jp/contests/abc157/tasks/abc157_b
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
    vector<vector<ll>> a33(3,vector<ll>(3));
    map<ll,pair<ll,ll>> tbl;
    FOR(y,0,3){
        FOR(x,0,3){
            ll a; cin>>a;
            tbl[a]={x,y};
        }
    }

    vector<vector<ll>> flag(3,vector<ll>(3,0)); 
    ll N; cin>>N;
    REP(i,N){
        ll b; cin>>b;
        auto it =tbl.find(b);
        if(it!=tbl.end()){
            auto p=it->second;
            flag.at(p.second).at(p.first)=1;
        }
    }
    //たて、よこ、ななめ
    bool ans=false;
    FOR(y,0,3){
        if (flag[y][0] && flag[y][1] && flag [y][2]){
            ans=true;
        }
        if (flag[0][y] && flag[1][y] && flag [2][y]){
            ans=true;
        }
    }
	if(flag[0][0] && flag[1][1] && flag[2][2]) {
		ans = true;
	}
	if(flag[0][2] && flag[1][1] && flag[2][0]) {
		ans = true;
	}
    cout<<(ans?"Yes":"No")<<endl;

	return 0;
}