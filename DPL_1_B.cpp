//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B&lang=ja
//0-1 Knapsack Problem
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
    ll N,W; cin>>N>>W;
    vector<pair<ll,ll>> vwn(N+1);
    FOR(i,0,N){
        auto&& vw=vwn.at(i);
        cin>>vw.first>>vw.second;
    }

    vector<vector<ll>> dp(N+2,vector<ll>(W+1)); //数,weight
    FOR(i,0,N){
        FOR(w,0,W+1){
            const auto& vw=vwn.at(i);
            if (w-vw.second<0){
                dp[i+1][w]=dp[i][w];
            }else{
                dp[i+1][w]=max(dp[i][w], dp[i][w-vw.second]+vw.first); //いれる
            }
        }
    }
    ll ans=0;
    FOR(w,0,W+1){
        ans=max(ans,dp[N][w]);
    }
    cout<<ans<<endl;
    return 0;
}