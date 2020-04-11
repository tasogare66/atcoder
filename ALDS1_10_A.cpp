//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_A&lang=ja
//Fibonacci Number
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
    ll n; cin>>n;
    vector<ll> dp(max(n+1,2LL));
    dp[0]=1;
    dp[1]=1;    
    FOR(i,2,n+1){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;
    return 0;
}