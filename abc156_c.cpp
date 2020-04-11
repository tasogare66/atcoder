//https://atcoder.jp/contests/abc156/tasks/abc156_c
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
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<ll> xn(N);
    for(auto&& x:xn){
        cin>>x;
    }
    ll ans=INT64_MAX;    
    FOR(i,0,100+1){
        ll p=i;
        ll val=0;
        FOR(j,0,xn.size()){
            ll d = p - xn.at(j);
            val += d*d;
        }
        ans=min(ans,val);
    }
    cout<<ans<<endl;
    return 0;
}