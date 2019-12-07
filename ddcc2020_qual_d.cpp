//https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_d
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
    ll M; cin>>M;
    ll sum=0;
    ll keta=0;
    REP(i,M){
        ll d,c; cin>>d>>c;
        sum += d*c;
        keta+=c;
    }
    ll ans=(sum-1)/9+keta-1;
    cout<<ans<<endl;
    return 0;
}