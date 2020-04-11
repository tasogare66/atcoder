//https://atcoder.jp/contests/joi2013yo/tasks/joi2013yo_d
//D - 暑い日々 (Hot days)
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
    ll D,N; cin>>D>>N;
    vector<ll> td(D);
    for(auto&& t:td) cin>>t;
    struct Info{
        ll a,b,c; //cが派手さ
    };
    vector<Info> infos(N);
    for(auto&& i:infos){
        cin>>i.a>>i.b>>i.c;
    }

    vector<vector<ll>> dp(D+1,vector<ll>(N,-1));
    FOR(fn,0,N){
        ll t=td.at(0);
        if(infos[fn].a>t||infos[fn].b<t) continue;           
        dp[0][fn]=0;
    }

    FOR(d,0,D-1){
        ll t=td.at(d+1);
        FOR(fn,0,N){ //服次
            //着れる?
            if(infos[fn].a>t||infos[fn].b<t) continue;
            FOR(fp,0,N){ //服前
                if(dp[d][fp]<0)continue;
                ll v = abs(infos[fn].c-infos[fp].c);
                chmax(dp[d+1][fn],dp[d][fp]+v);
            }
        }
    }
    dump(dp);
    ll ans=0;
    FOR(i,0,N){
        chmax(ans,dp[D-1][i]);
    }
    cout<<ans<<endl;

    return 0;
}