//https://atcoder.jp/contests/abc147/tasks/abc147_a
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
    ll a1,a2,a3; cin>>a1>>a2>>a3;
    ll ans=a1+a2+a3;
    if(ans>=22) cout<<"bust"<<endl;
    else cout<<"win"<<endl;
    return 0;
}