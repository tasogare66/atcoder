//
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
    ll N, K; cin>>N>>K;
    vector<ll> an(N);

    sort(an.begin(),an.end());

    vector<ll> an_p;//+
    vector<ll> an_z;//0
    vector<ll> an_m;//-

    auto check_func = [&](ll val)->bool{
        ll num = 0;
        for(const auto& a:an){
            ll tmp=val/a;
            lower_bound(an.begin(),an.end(),tmp);
        }        
    };

    ll lb=-1e+18-13,ub=1e+18+13;
    while(ub-lb>1){
        ll mid=(ub+lb)/2;
        auto ck = check_func(mid);
        if (ck){
            lb=mid;
        }else{
            ub=mid;
        }
        dump(mid,ck,lb,ub);
    }


    return 0;
}