//https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_g
//G - あまり
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
    ll N; cin>>N;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    reverse(an.begin(),an.end());
    ll ans=0;
    ll mul=1;
    FOR(i,0,N){
        ll a=an.at(i);
        ans += (mul * a)%MOD;
        ans %= MOD;

        ll t = log10(a)+1;
        //dump(t);
        REP(j,t){
            mul = (mul * 10)%MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}