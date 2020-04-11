//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=ja
// Longest Common Subsequence
// LCS
//http://nocotan.github.io/%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0/2017/01/23/lcs-copy.html
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
void solve(){
    string X,Y; cin>>X>>Y;
    vector<vector<ll>> dp(X.size()+1,vector<ll>(Y.size()+1));
    //max | dp[i][j]=dp[i-1][j-1]+1, 文字が同じとき
    //max | dp[i][j]=dp[i-1][j]
    //max | dp[i][j]=dp[i][j-1]
    FOR(i,0,X.size()){
        FOR(j,0,Y.size()){
            if(X[i]==Y[j]) chmax(dp[i+1][j+1],dp[i][j]+1);
            chmax(dp[i+1][j+1],dp[i][j+1]);
            chmax(dp[i+1][j+1],dp[i+1][j]);
        }
    }
    cout<<dp[X.size()][Y.size()]<<endl;
}
int main() {
    ll q; cin>>q;    
    REP(i,q){
        solve();
    }
    return 0;
}