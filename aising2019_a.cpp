//https://atcoder.jp/contests/aising2019/tasks/aising2019_a
//A - Bulletin Board
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
    ll N,H,W; cin>>N>>H>>W;    
    ll a=N-H+1;
    ll b=N-W+1;
    cout<<a*b<<endl;
    return 0;
}