//https://atcoder.jp/contests/dp/tasks/dp_i
//I - Coins
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
    ll N; cin>>N;
    vector<double> pn(N+1);
    FOR(i,0,N){
        cin>>pn.at(i);
    }    
    vector<vector<double>> dp(N+1,vector<double>(N+1,0)); //回数,表
    dp[0][0]=1;
    FOR(i,0,N){
        FOR(omote,0,N+1){
            dp[i+1][omote] += dp[i][omote]*(1.0-pn[i]);
            dp[i+1][omote+1] += dp[i][omote]*pn[i];
        }
    }
    double ans=0;
    FOR(omote,0,N+1){
        if(N-omote<omote) ans+=dp[N][omote];
    }
    cout<<fixed<<std::setprecision(10)<<ans<<endl;
}
int main_() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<double> pn(N+1);
    FOR(i,1,N+1){
        cin>>pn.at(i);
    }    
    vector<vector<double>> dp(N+1,vector<double>(N+1));
    dp[0][0]=1;
    auto dpij = [&](ll i,ll j)->double{
        if (i<0||i>N) return 0;
        if (j<0||j>N) return 0;
        return dp[i][j];
    };
    FOR(i,0,N+1){
        FOR(j,0,N+1){
            if(i==0&&j==0) continue;
            ll tm=i+j; //回目
            if(tm>=pn.size()) continue;
            dump(tm,i,j); //表、うら
            auto p=pn.at(tm);
            dp[i][j] = p*dpij(i-1,j) + (1.0f-p)*dpij(i,j-1);
        }
    }
    dump(dp);
    double ans=0;
    FOR(i,0,N+1){
        FOR(j,0,N+1){
            if(i+j==N&&i>j) ans+=dp[i][j];
        }
    }
    cout<<fixed<<std::setprecision(10)<<ans<<endl;
    return 0;
}