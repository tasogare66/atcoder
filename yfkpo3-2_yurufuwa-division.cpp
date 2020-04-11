//https://www.hackerrank.com/contests/yfkpo3-2/challenges/yurufuwa-division
//Yurufuwa Division
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
    ll X,A; cin>>X>>A;    
    if(X<=A) cout<<1<<endl;
    else cout<<2<<endl;
    return 0;
}