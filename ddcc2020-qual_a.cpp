//https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_a
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
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll X, Y;cin>>X>>Y;
    vector<ll> tbl={
        0,300000,200000,100000,
    };
    ll ans=0;
    ans+=X<tbl.size()?tbl.at(X):0;
    ans+=Y<tbl.size()?tbl.at(Y):0;
    if (X==1&&Y==1) ans+=400000;

    cout<<ans<<endl;
    return 0;
}