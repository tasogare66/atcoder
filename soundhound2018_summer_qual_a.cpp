//https://atcoder.jp/contests/soundhound2018-summer-qual/tasks/soundhound2018_summer_qual_a
//A - F
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
    ll a,b; cin>>a>>b;
    if(a+b==15) cout<<"+"<<endl;
    else if(a*b==15) cout<<"*"<<endl;
    else cout<<"x"<<endl;
    return 0;
}