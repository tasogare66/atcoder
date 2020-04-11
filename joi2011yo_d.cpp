//https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_d
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
    //std::ifstream in("./test/sample-1.in");
    std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }

    auto check = [](ll v){
        if (v<0) return false;
        if (v>20) return false;
        return true;
    };

    vector<vector<ll>> dp(N,vector<ll>(21,0));
    dp[0][0]=1;
    FOR(i,0,N-1){
        auto a=an[i];
        dump(a);
        FOR(j,0,21){
            if (check(j+a)) dp[i+1][j+a]+=(dp[i][j]);
            if (check(j-a) && i!=0) dp[i+1][j-a]+=(dp[i][j]); //先頭が0だとbugる
        }
    }
    dump(an.back());
    cout<<dp[N-1][an.back()]<<endl;
    return 0;
}
