//https://atcoder.jp/contests/dp/tasks/dp_c
//C - Vacation
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
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;    
    vector<vector<ll>> dp(3,vector<ll>(N+1,0));
    auto get_v = [&](ll p, ll point, ll abc){
        ll d0;
        ll d1;
        if (abc==0){
            d0=1,d1=2;
        } else if(abc==1){
            d0=0,d1=2;
        }else{
            d0=0,d1=1;
        }
        return max(dp[d0][p-1]+point,dp[d1][p-1]+point);
    };
    FOR(i,1,N+1){
        ll a,b,c; cin>>a>>b>>c;
        //a
        dp[0][i] = get_v(i, a, 0);
        //b
        dp[1][i] = get_v(i, b, 1);
        //c
        dp[2][i] = get_v(i, c, 2);
    }
    ll ans=0;
    REP(i,3){
        ans=max(ans,dp[i][N]);
    }
    cout<<ans<<endl;    
    return 0;
}