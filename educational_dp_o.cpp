//https://atcoder.jp/contests/dp/tasks/dp_o
//O - Matching
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
constexpr ll MOD=1e9+7;
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif   
    ll N; cin>>N;
    vector<vector<ll>> ann(N, vector<ll>(N));
    for(auto&& an:ann){
        for(auto&& a:an){
            cin>>a;
        }
    }

    ll mask_max=1<<N;
    vector<ll> dp(mask_max,0);
    dp[0]=1;
    FOR(i,1,mask_max){
        ll man_no = __builtin_popcountll(i)-1;
        FOR(w,0,N){
            ll w_mask = 1<<w;
            if (w_mask & i){
                ll m_mask = (~w_mask) & i;
                dp.at(i) += dp.at(m_mask) * ann[man_no][w];
                dp[i] %= MOD;
            }
        }
    }
    cout<<dp[mask_max-1]<<endl;
    return 0;
}
