//https://atcoder.jp/contests/gigacode-2019/tasks/gigacode_2019_c
//C - パソコンの購入
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
    ll D; cin>>D;
    vector<ll> ad(D);
    vector<ll> bd(D);
    for(auto&& a:ad){
        cin>>a;
    }
    for(auto&& b:bd){
        cin>>b;
    }
    ll ans=INT64_MAX;
    ll sum=0;
    REP(i,D){
        sum+=ad.at(i);
        if(sum>=bd.at(i)){
            ans=min(ans,bd.at(i));
        }
    }
    if(ans==INT64_MAX) ans=-1;
    cout<<ans<<endl;
    return 0;
}