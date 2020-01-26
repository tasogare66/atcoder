//https://atcoder.jp/contests/keyence2020/tasks/keyence2020_c
//C - Subarray Sum
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
    ll N,K,S; cin>>N>>K>>S;
    vector<ll> an(N);
    FOR(i,0,K){
        an[i]=S;
    }
    auto tmp=S+1;
    if(tmp>1e+9) tmp=1;
    FOR(i,K,N){
        an[i]=tmp;
    }
    REP(i,N){
        if(i!=0)cout<<" ";
        cout<<an.at(i);
    }
    cout<<endl;
    return 0;
}