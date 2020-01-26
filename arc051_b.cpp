//https://atcoder.jp/contests/arc051/tasks/arc051_b
//B - 互除法
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
    ll K; cin>>K;
    int counter = 0;
    function<int(int,int)> gcd=[&](int a, int b) {
        dump(counter,a,b);
        if (b == 0) return a;
        counter++;
        return gcd(b, a%b);
    };
    auto test = [&](int a, int b){
        counter=0;
        auto result = gcd(a,b);
        dump(counter, result);
    };
    //test(4,5);
    // int a,b; cin>>a>>b;
    // test(a,b);

    ll a=1,b=0;
    FOR(i,0,K+1){
        ll nb=a;
        ll na=a*1+b;
        a=na;
        b=nb;
        dump(i,a,b);
    }
    //test(a,b);
    cout<<a<<" "<<b;
    return 0;
}