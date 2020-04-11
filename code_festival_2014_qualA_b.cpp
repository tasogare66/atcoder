//https://atcoder.jp/contests/code-festival-2014-quala/tasks/code_festival_qualA_b
//B - とても長い文字列
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
    string A; cin>>A;
    ll B; cin>>B;
    ll p = (B-1) % A.size();
    cout<<A.at(p)<<endl;
    return 0;
}