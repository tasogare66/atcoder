//https://atcoder.jp/contests/abc114/tasks/abc114_d
//D - 756
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
std::vector<std::pair<T,T>> prime_factor_decomp(T n) {
    std::vector<std::pair<T,T>> pe_tbl;
    T m = n;
    for (T i = 2; i * i <= n; i++) {
        if (m % i != 0) continue;
        T c = 0;
        while (m % i == 0) c++, m /= i;
        pe_tbl.emplace_back(i,c);
    }
    if (m > 1) {
        pe_tbl.emplace_back(m,1);
    }
    return pe_tbl;
}

int main() {
    ll N=10; cin>>N;
    auto base = prime_factor_decomp(75LL);
    dump(base);
    auto tmp = prime_factor_decomp(32400LL);
    dump(tmp);
    tmp = prime_factor_decomp(362880LL);
    dump(tmp);
    unordered_map<ll,ll> pd_tbl;
    FOR(i,1,N+1){
        auto rs = prime_factor_decomp(i);
        for(const auto& r:rs){
            pd_tbl[r.first] += r.second;
        }
    }
    dump(pd_tbl);
    ll ov4 = 0;
    ll ov2_3 = 0;

    ll ov74 = 0;

    ll ov14 = 0;
    ll ov4_2 = 0;

    ll ov24 = 0;
    ll ov2 = 0;
    for (const auto& i:pd_tbl) {
        if (i.second>=4){
            ++ov4;
        }else if(i.second>=2){
            ++ov2_3;
        }
        if (i.second >= 74) {
            ++ov74;
        }
        if (i.second >= 14){
            ++ov14;
        }else if(i.second>=4){
            ++ov4_2;
        }
        if (i.second >= 24){
            ++ov24;
        }else if(i.second>=2){
            ++ov2;
        }
    }
    dump(ov4,ov2_3,ov74);
    ll ans = ov4 * (ov4-1) / 2;
    ans *= ((ov4-2)+ov2_3);
    ans += (ov74); //74
    ans += ov14 * (ov4_2-1+ov14); //15*5
    ans += ov24 * (ov24-1+ov2); //25*3
    cout<<ans<<endl;
    return 0;
}