//https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_c
//C - カラオケ
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
    ll N,M; cin>>N>>M;
    vector<vector<ll>> anm(N+1,vector<ll>(M+1));
    FOR(i,1,N+1){
        FOR(j,1,M+1){
            cin>>anm[i][j];
        }
    }

    auto calc = [&](ll t1,ll t2){
        ll result =0;
        FOR(n,1,N+1){
            auto s1 = anm.at(n).at(t1);
            auto s2 = anm.at(n).at(t2);
            result += max(s1,s2);
        }
        return result;
    };
    ll ans=0;
    FOR(t1,1,M+1){
        FOR(t2,t1+1,M+1){
            chmax(ans,calc(t1,t2));
        }
    }    
    cout<<ans<<endl;
    return 0;
}