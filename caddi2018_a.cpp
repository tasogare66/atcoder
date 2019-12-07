//https://atcoder.jp/contests/caddi2018/tasks/caddi2018_a
//C - Product and GCD
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

template< typename T >
std::pair<std::vector<T>, std::vector<T>> prime_factor_decomp(T n) {
    std::vector<T> p, e;
    T m = n;
    for (T i = 2; i * i <= n; i++) {
        if (m % i != 0) continue;
        T c = 0;
        while (m % i == 0) c++, m /= i;
        p.push_back(i);
        e.push_back(c);
    }
    if (m > 1) {
        p.push_back(m);
        e.push_back(1);
    }
    return std::make_pair(p, e);
}

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-4.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,P; cin>>N>>P;
    auto r=prime_factor_decomp(P);
    ll ans=1;
    REP(i,r.first.size()){
        ll num=r.second.at(i) / N;
        REP(j,num){
            ans*=r.first.at(i);
        }
    }
    cout<<ans<<endl;
    return 0;
}