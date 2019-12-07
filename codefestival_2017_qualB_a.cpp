//https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_a
//A - XXFESTIVAL
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
    string S; cin>>S;    
    REP(i,8){
        S.pop_back();
    }
    cout<<S<<endl;
    return 0;
}