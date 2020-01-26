//https://atcoder.jp/contests/keyence2020/tasks/keyence2020_a
//A - Painting
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
    ll H,W; cin>>H>>W;
    ll N; cin>>N;
    ll mx=max(H,W);    
    ll ans= (N+mx-1)/mx;
    cout<<ans<<endl;
    return 0;
}