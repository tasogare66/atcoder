//https://atcoder.jp/contests/abc147/tasks/abc147_b
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
    ll ans=0;
    for(ll i=0;i<S.size();++i){
        ll p=S.size()-i-1;
        if(S.at(i)!=S.at(p)) ++ans;
    }
    cout<<ans/2<<endl;
    return 0;
}