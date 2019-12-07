//https://atcoder.jp/contests/apc001/tasks/apc001_a
//A - Two Integers
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
    ll X,Y; cin>>X>>Y;
    if (X%Y==0) {
        cout<<-1<<endl;
    } else {
        cout<<(X*(Y+1))<<endl;
    }
    return 0;
}