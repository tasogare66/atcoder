//https://atcoder.jp/contests/abc149/tasks/abc149_c
//C - Next Prime
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

bool is_prime(const ll n){
    switch(n){
    case 0: // fall-through
    case 1: return false;
    case 2: return true;
    }
    if(n%2 == 0) return false;
    //i=3から奇数のみ調べる
    for(ll i=3;i*i<=n;i+=2){
        if(n%i == 0) return false;
    }
    return true;
}

int main() {
    ll X; cin>>X;
    while(!is_prime(X)){
        ++X;
    }
    cout<<X<<endl;
    return 0;
}