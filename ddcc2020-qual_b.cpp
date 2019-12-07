//https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_b
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
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<ll> an;
    for(ll i=1;i<=N;++i){
        ll a; cin>>a;
        an.push_back(a);
    }

    ll s=0;
    vector<ll> sumt;
    REP(i,an.size()){
        s+=an.at(i);
        sumt.push_back(s);
    }

    ll ans=INT64_MAX;
    FOR(i,0,an.size()){
        ll l = sumt.at(i);
        ll r = s - sumt.at(i);
        ans = min(abs(l-r),ans);
    }

    cout<<ans<<endl;

    return 0;
}