//https://atcoder.jp/contests/abc146/tasks/abc146_a
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
    map<string,ll> tbl={
        {"SUN",7},
        {"MON",6},
        {"TUE",5},
        {"WED",4},
        {"THU",3},
        {"FRI",2},
        {"SAT",1},
    };    
    cout<<tbl[S]<<endl;
    return 0;
}