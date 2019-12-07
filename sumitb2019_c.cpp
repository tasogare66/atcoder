//https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_c
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
    ll X; cin>>X;    

    auto check_func =[&](ll n){
        ll mi=n*100;
        ll mx=n*105;
        return (mi<=X&&X<=mx);
    };
    ll num=X/100;
    bool ans=false;
    FOR(i,1,num+1){
        ans|=check_func(i);
    }
    cout<<ans<<endl;
    return 0;
}