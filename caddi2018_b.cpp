//https://atcoder.jp/contests/caddi2018/tasks/caddi2018_b
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
    bool allev=true;
    REP(i,N){ //全部偶数だったらsecond
        ll a; cin>>a;
        if(a%2!=0)allev=false;
    }
    cout<<(allev?"second":"first")<<endl;
    return 0;
}