//https://atcoder.jp/contests/abc153/tasks/abc153_d
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
    ll H; cin>>H;
    ll ans=0;
    ll num=1;
    //sim
    while(H>0){
        ans += num;
        num *= 2;
        H/=2;
    }
    cout<<ans<<endl;    
    return 0;
}