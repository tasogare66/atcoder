//https://atcoder.jp/contests/exawizards2019/tasks/exawizards2019_b
//B - Red or Blue
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
    string s; cin>>s;
    ll r=0,b=0;
    for(auto& c:s){
        if(c=='R')++r;
        else ++b;
    }
    cout<<(r>b?"Yes":"No")<<endl;
    return 0;
}