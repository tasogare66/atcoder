//https://atcoder.jp/contests/gigacode-2019/tasks/gigacode_2019_b
//B - 採用面接
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
    ll N,X,Y,Z; cin>>N>>X>>Y>>Z;
    ll ans=0;
    REP(i,N){
        ll a,b; cin>>a>>b;
        if(a>=X&&b>=Y&&a+b>=Z)++ans;
    }
    cout<<ans<<endl;
    return 0;
}