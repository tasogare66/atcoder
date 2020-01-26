//https://atcoder.jp/contests/dp/tasks/dp_d
//D - Knapsack 1
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
    ll N,W; cin>>N>>W;
    vector<pair<ll,ll>> wvn(N+1);
    FOR(i,1,N+1){
        cin>>wvn[i].first>>wvn[i].second;
    }
    vector<vector<ll>> dp(N+1,vector<ll>(W+1,0));
    FOR(i,1,N+1){
        ll w=wvn[i].first;
        ll v=wvn[i].second;
        FOR(j,1,W+1){
            dp[i][j]=dp[i-1][j];
            if (j-w>=0) {
                dp[i][j]=max(dp[i-1][j-w]+v,dp[i][j]);
            }
        }
    }
    ll ans=0;
    FOR(i,1,N+1){
        chmax(ans, dp[i][W]);
    }
    cout<<ans<<endl;
    return 0;
}