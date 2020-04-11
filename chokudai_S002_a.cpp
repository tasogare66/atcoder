//https://atcoder.jp/contests/chokudai_S002/tasks/chokudai_S002_a
//A - 長方形 α
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
    vector<ll> ans(N);
    REP(i,N){
        ll A,B;
        cin>>A>>B;
        ans.at(i) = A*B;
    }
    for(const auto& v:ans){
        cout<<v<<endl;
    }    
    return 0;
}