//https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_d
//D - パスタ (Pasta)
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
constexpr ll MOD=10000;
int main(){
#if LOCAL&01
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,K; cin>>N>>K;
    unordered_map<ll,ll> abk;
    REP(i,K){
        ll a,b; cin>>a>>b;
        abk[a]=b;
    }

    vector<vector<vector<ll>>> dp(N+1,vector<vector<ll>>(4,vector<ll>(4)));
    //初日いれる
    dp[0][1][1]=1;
    FOR(d,0,N){
        auto it = abk.find(d+1);
        ll force = -1;
        if(it!=abk.end())force=it->second;
        FOR(a,1,4){
            if (force!=-1&&force!=a)continue;
            FOR(b,1,4){
                FOR(c,1,4){
                    if (d>=2&&a==b&&b==c)continue; //3日までは連続判定いれない
                    dp[d+1][a][b]+=dp[d][b][c];
                    dp[d+1][a][b] %= MOD;
                }
            }
        }
    }

    ll ans=0;
    FOR(i,1,4){
        FOR(j,1,4){
            ans += dp[N][i][j];
            ans %= MOD;
        }
    }
    cout<<ans<<endl;

    return 0;
}
int main_() {
#if LOCAL&01
    std::ifstream in("./test/sample-2.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,K; cin>>N>>K;
    unordered_map<ll,ll> abk;
    REP(i,K){
        ll a,b; cin>>a>>b;
        abk[a]=b;
    }
    vector<vector<ll>> dp(4,vector<ll>(N+1));
    if (abk.count(1)>0){
        dp[abk[1]][1]=1;
    }else{
        FOR(p,1,4){
            dp[p][1]=1;
        }
    }

    FOR(d,1,N){
        auto it = abk.find(d+1);
        ll force = -1;
        if(it!=abk.end())force=it->second;
        FOR(p,1,4){
            FOR(t,1,4){
                dp[p][d+1]+=dp[t][d];
            }
            dp[p][d+1]-=min(dp[p][d-1],dp[p][d]);
            if(force!=-1&&force!=p){
                dp[p][d+1]=0;
            }
        }
    }
    dump(abk);
    dump(dp);
    ll ans=0;
    FOR(p,1,4){
        ans += dp[p][N];
        //ans %= MOD;
    }
    cout<<ans<<endl;
    return 0;
}