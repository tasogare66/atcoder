//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_A&lang=ja
//Coin Changing Problem
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
    ll n,m; cin>>n>>m;
    vector<ll> cm(m);
    for(auto&& c:cm) cin>>c;
#if 01
    vector<ll> dp(n+1,INT32_MAX); //1次元dpでよい
    dp[0]=0;
    FOR(i,0,m){
        FOR(j,0,n+1){
            auto c=cm[i];
             if(j-c>=0){
                chmin(dp[j],dp[j-c]+1);
             }
        }
    }
    cout<<dp[n]<<endl;
#elif 0
    vector<vector<ll>> dp(m+1,vector<ll>(n+1,INT32_MAX)); //[m種類コイン][n円]
    dp[0][0]=0;
    FOR(i,0,m){
        FOR(j,0,n+1){
            auto c=cm[i];
            if (dp[i][j]<INT32_MAX) chmin(dp[i+1][j],dp[i][j]);
            if(j-c>=0){
                if (dp[i][j-c]<INT32_MAX) chmin(dp[i+1][j],dp[i][j-c]+1);
                if (dp[i+1][j-c]<INT32_MAX) chmin(dp[i+1][j], dp[i+1][j-c]+1);
            }
        }
    }
    cout<<dp[m][n]<<endl;
#else
    vector<vector<ll>> dp(m+1,vector<ll>(n+1,INT32_MAX)); //[m種類コイン][n円]
    dp[0][n]=0;
    FOR(i,0,m){
        for(ll j=n;j>=0;--j){
            dp[i+1][j]=dp[i][j];
            auto c = cm[i];
            if(j-c>=0){
                dp[i+1][j]=min(dp[i+1][j],dp[i][j-c]+1);
                dp[i+1][j]=min(dp[i+1][j],dp[i+1][j-c]+1);
            }
        }
    }
    cout<<dp[m][n]<<endl;
#endif
    return 0;
}