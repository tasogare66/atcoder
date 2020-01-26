//https://atcoder.jp/contests/abc148/tasks/abc148_c
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
ll lcm(ll num1,ll num2){
    return num1 / __gcd(num1,num2) * num2;
}
int main() {
    ll A,B; cin>>A>>B;
    ll ans=lcm(A,B);
    cout<<ans<<endl;
    return 0;
}