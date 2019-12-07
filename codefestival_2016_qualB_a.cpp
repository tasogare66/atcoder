//https://atcoder.jp/contests/code-festival-2016-qualb/tasks/codefestival_2016_qualB_a
//A - Signboard
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
    string b="CODEFESTIVAL2016";
    assert(S.size()==b.size());
    ll ans=0;
    REP(i,S.size()){
        if(S.at(i)!=b.at(i)) ++ans;
    }
    cout<<ans<<endl;
    return 0;
}