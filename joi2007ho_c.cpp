//https://atcoder.jp/contests/joi2007ho/tasks/joi2007ho_c
//C - 最古の遺跡
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
    ll n; cin>>n;
    vector<pair<ll,ll>> ps(n);
    set<pair<ll,ll>> tbl;
    for(auto&& p:ps){
        cin>>p.first>>p.second;
        tbl.insert(p);
    }    

    auto search_func = [&](const auto& p, const auto& v)->ll{
        auto it = tbl.find(p);
        if (it != tbl.end()){
            pair<ll,ll> l = {p.first+v.first, p.second+v.second};
            auto it2 = tbl.find(l);
            if (it2 != tbl.end()) {
                return v.first*v.first + v.second*v.second;
            }
        }
        return 0;
    };

    ll ans=0;
    FOR(i,0,n){
        FOR(j,i+1,n){
            const auto& p0=ps[i];
            const auto& p1=ps[j];
            ll vx=p1.first-p0.first;
            ll vy=p1.second-p0.second;
            pair<ll,ll> vec={vx,vy};
            //90
            pair<ll,ll> p90={-vy+p0.first, vx+p0.second};
            ans = max(ans,search_func(p90, vec));
            //-90
            pair<ll,ll> pr90={vy+p0.first, -vx+p0.second};
            ans = max(ans,search_func(pr90, vec));
        }
    }
    cout<<ans<<endl;
    return 0;
}