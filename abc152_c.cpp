//https://atcoder.jp/contests/abc152/tasks/abc152_c
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
    ll N; cin>>N;
    vector<ll> pn(N);    
    for(auto&& p:pn){
        cin>>p;
    }
    ll ans=0;
    ll min_v=INT64_MAX;
    for(auto& p:pn){
        if (chmin(min_v, p)){
            ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}