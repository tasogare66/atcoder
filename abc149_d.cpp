//https://atcoder.jp/contests/abc149/tasks/abc149_d
//D - Prediction and Restriction
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
    ll N,K; cin>>N>>K;
    ll R,S,P; cin>>R>>S>>P;
    string T; cin>>T;
    vector<vector<ll>> dp(2,vector<ll>(N,0));
    auto get_score = [&](char c)->ll{
        if(c=='r') return P;
        if(c=='s') return R;
        if(c=='p') return S;
        assert(0);
        return 0;
    };
    for(ll i=0;i<K;++i){
        dp[0][i] = get_score(T.at(i));
    }
    FOR(j,0,K){
        for(ll i=j+K;i<N;i+=K){
            ll nxt=i;
            ll cur=i-K;
            if(T.at(cur)==T.at(nxt)){
                dp[0][nxt] = dp[1][cur] + get_score(T.at(nxt));
                dp[1][nxt] = max(dp[0][cur],dp[1][cur]);
            }else{
                dp[0][nxt] = max(dp[0][cur],dp[1][cur]) + get_score(T.at(nxt));
                dp[1][nxt] = max(dp[0][cur],dp[1][cur]);
            }
        }
    }
    ll ans=0;
    for(ll j=0;j<K;++j){
        ans += max(dp[0][N-1-j],dp[1][N-1-j]);
    }
    cout<<ans<<endl;
    return 0;
}