//https://atcoder.jp/contests/dp/tasks/dp_e
//E - Knapsack 2
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
    ll N,W; cin>>N>>W;
    ll V=0;
    vector<pair<ll,ll>> wvn(N+1); //w,v
    FOR(i,1,N+1){
        cin>>wvn[i].first>>wvn[i].second;
        V+=wvn[i].second;
    }
    ll INFW=1e+11;
    vector<vector<ll>> dp(N+2,vector<ll>(V+1,INFW));
#if 1
    dp[1][0]=0;
    FOR(i,1,N+1){
        ll w=wvn[i].first;
        ll v=wvn[i].second;
        FOR(j,0,V+1){
            if(j<v){
                dp[i+1][j]=dp[i][j];
            }else{
                dp[i+1][j]=min(dp[i][j], dp[i][j-v]+w);
            }
        }
    }
    ll res=0;
    FOR(i,0,V+1) if (dp[N+1][i]<=W) res=i;
    cout<<res<<endl;
#else
    FOR(j,0,V+1){
        dp[0][j]=0;
    }
    FOR(i,1,N+1){
        ll w=wvn[i].first;
        ll v=wvn[i].second;
        FOR(j,0,V+1){
            if (j-v>=0) {
                dp[i][j]=min(dp[i-1][j-v]+w,dp[i][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    ll ans=0;
    FOR(i,0,V+1){
        if (dp[N][i]<=W) chmax(ans,i);
    }
    cout<<ans<<endl;
#endif
    return 0;
}