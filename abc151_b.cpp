//https://atcoder.jp/contests/abc151/tasks/abc151_b
//B - Achieve the Goal
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
    ll N, K, M; cin>>N>>K>>M;
    vector<ll> an(N-1);
    ll sum=0;
    for(auto&& a:an){
        cin>>a;
        sum+=a;
    }
    ll ans = N*M - sum;
    ans = max(ans,0LL);
    if (ans>K) ans=-1;
    cout<<ans<<endl;
    return 0;
}