//https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_a
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
    ll m1,d1; cin>>m1>>d1;
    ll m2,d2; cin>>m2>>d2;
    if(m1!=m2){
        cout<<1<<endl;
    } else{
        cout<<0<<endl;
    }   
    return 0;
}