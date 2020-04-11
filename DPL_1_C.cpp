//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C&lang=ja
//Knapsack Problem
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
    struct info {
        info(){}
        void set(ll iv,ll iw){
            v=iv, w=iw;
            vpw=(float)v/(float)w;
        }
        ll v=0,w=0;
        float vpw=0;
    };
    vector<info> vwn(N);
    for(auto&& vw:vwn){
        ll v,w; cin>>v>>w;
        vw.set(v,w);
    }

    vector<vector<ll>> dp(N+1,vector<ll>(W+1)); //数,weight
    FOR(i,0,N){
        FOR(w,0,W+1){
#if 01
            const auto& vw=vwn.at(i);
            dp[i+1][w]=max(dp[i+1][w],dp[i][w]);
            if(w-vw.w>=0) {
                dp[i+1][w]=max(dp[i+1][w], dp[i][w-vw.w]+vw.v); //いれる
                dp[i+1][w]=max(dp[i+1][w], dp[i+1][w-vw.w]+vw.v); //重複をゆるす
            }
#else
            const auto& vw=vwn.at(i);
            dp[i+1][w]=dp[i][w];
            auto num = w / vw.w;
            REP(n,num+1){
                dp[i+1][w]=max(dp[i+1][w], dp[i][w-vw.w*n]+vw.v*n); //いれる
            }
#endif
        }
    }
    ll ans=dp[N][W];
    // FOR(w,0,W+1){
    //     ans=max(ans,dp[N][w]);
    // }
    cout<<ans<<endl;
    return 0;
}