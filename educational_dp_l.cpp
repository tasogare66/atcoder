//https://atcoder.jp/contests/dp/tasks/dp_l
//L - Deque
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
    ll N; cin>>N;
    vector<ll> an(N);
    FOR(i,0,N){
        cin>>an.at(i);
    }
    vector<vector<ll>> dp(N+1,vector<ll>(N+1)); //i,j区間 [i,j)=x-yの値
    FOR(i,0,N+1){
        FOR(j,0,N+1){
            if(i==j) {dp[i][j]=0;continue;}
            if(i>j) {dp[i][j]=-1;continue;}
            bool taro=(j-i)%2;
            dump(i,j,taro);
            if(taro){
//                dp[i][j]=max(dp[i+1][j]+an[i],dp[i][j+1]+an[j]);
            }else{
//                dp[i][j]=min(dp[i+1][j]-an[i],dp[i][j+1]-an[j]);;
            }
        }
    }
    dump(dp);
    return 0;
}