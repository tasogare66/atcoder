//https://atcoder.jp/contests/joi2020yo1c/tasks/joi2020_yo1c_c
//C - 最長昇順連続部分列 (Longest Ascending Contiguous Subsequence)
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
    vector<ll> an(N);
    ll ans=0;
    ll len=0;
    ll prev=INT64_MIN;
    for(auto&& a:an){
        cin>>a;
        if (prev<=a) {
            ++len;
            ans=max(len,ans);
        }else{
            len=1;
        }
        prev=a;
    }
    cout<<ans<<endl;
    return 0;
}