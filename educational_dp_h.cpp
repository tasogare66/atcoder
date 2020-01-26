//https://atcoder.jp/contests/dp/tasks/dp_h
//H - Grid 1
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
    ll H,W; cin>>H>>W;
    vector<string> awh(H);
    for(auto&& aw:awh){
        cin>>aw;
    }   
    vector<vector<ll>> dp(H,vector<ll>(W));
    auto get_val = [&](ll y,ll x)->ll{
        if (y<0||y>=H) return 0;
        if (x<0||x>=W) return 0;
        if (awh.at(y).at(x)=='#') return 0;
        return dp[y][x];
    };
    dp[0][0]=1;
    FOR(y,0,H){
        FOR(x,0,W){
            if (x==0&&y==0)continue; //FIXME:...
            dp[y][x]=(get_val(y,x-1)+get_val(y-1,x))%MOD;
        }
    }
    dump(dp);
    cout<<dp[H-1][W-1]<<endl;
    return 0;
}