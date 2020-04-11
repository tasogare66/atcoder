//https://atcoder.jp/contests/abc154/tasks/abc154_a
//A - Remaining Balls / 
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
    string S,T; cin>>S>>T;
    ll A,B; cin>>A>>B;
    string U; cin>>U;
    if (S==U)--A;
    else if (T==U)--B;
    else assert(0);
    cout<<A<<" "<<B<<endl;
    return 0;
}