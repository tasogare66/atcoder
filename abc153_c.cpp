//https://atcoder.jp/contests/abc153/tasks/abc153_c
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
    ll N,K; cin>>N>>K;
    vector<ll> hn(N);
    for(auto&&h:hn){
        cin>>h;
    }    
    sort(hn.begin(),hn.end(),greater<ll>());
    ll ans=0;
    FOR(i,K,hn.size()){
        ans += hn.at(i);
    }
    cout<<ans<<endl;
    return 0;
}