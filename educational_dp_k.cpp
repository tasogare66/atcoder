//https://atcoder.jp/contests/dp/tasks/dp_k
//K - Stones
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
    ll N,K; cin>>N>>K;
    ll mina=INT64_MAX;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
        chmin(mina,a);
    }
    vector<vector<ll>> dp(K+1,vector<ll>(2,0)); //残り数,player0,1
    FOR(i,1,K+1){
        FOR(p,0,2){ //player
            ll wl=0;
            ll op=p==0?1:0;
            FOR(ap,0,N){
                auto a=an.at(ap);
                if(i>=a){
                    wl |= !dp[i-a][op];
                }
            }
            dp[i][p]=wl;
        }
    }
    dump(dp);
    cout<<(dp[K][0]?"First":"Second")<<endl;
    return 0;
}