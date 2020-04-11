//https://atcoder.jp/contests/abc155/tasks/abc155_a
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
    set<ll> tmp;
    REP(i,3){
        ll v; cin>>v;
        tmp.insert(v);
    }
    if(tmp.size()==2)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}