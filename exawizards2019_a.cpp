//https://atcoder.jp/contests/exawizards2019/tasks/exawizards2019_a
//A - Regular Triangle
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
    vector<ll> abc(3);
    for(auto&& e:abc){
        cin>>e;
    }
    if(abc[0]==abc[1]&&abc[1]==abc[2]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}