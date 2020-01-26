//https://atcoder.jp/contests/dwacon5th-prelims/tasks/dwacon5th_prelims_a
//A - Thumbnail
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
    double ave=0;
    for(auto&& a:an){
        cin>>a;
        ave += a;
    }
    ave /= (double)(N);
    ll ans=0;
    double dist=INT64_MAX;
    FOR(i,0,N){
        if (chmin(dist,abs((double)an.at(i)-ave))) {
            ans = i;
        }
    }
    cout<<ans<<endl;
    return 0;
}