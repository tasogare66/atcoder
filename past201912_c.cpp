//https://atcoder.jp/contests/past201912-open/tasks/past201912_c
//C - 3 番目 / The Third
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
    vector<ll> af(6);
    for(auto&& v:af){
        cin>>v;
    }    
    sort(af.begin(),af.end(),greater<ll>());
    cout<<af.at(3-1)<<endl;
    return 0;
}