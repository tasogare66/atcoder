//https://atcoder.jp/contests/abc153/tasks/abc153_b
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
    ll H, N;cin>>H>>N;
    vector<ll> an(N);
    ll sum=0;
    for(auto&& a:an){
        cin>>a;
        sum+=a;
    }
    bool ans=(sum>=H)?true:false;
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}