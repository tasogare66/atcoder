//https://atcoder.jp/contests/abc153/tasks/abc153_f
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
int main(){
#if LOCAL&01
    std::ifstream in("./test/sample-3.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,D,A; cin>>N>>D>>A;
    vector<pair<ll,ll>> xhn(N);
    for(auto&& xh:xhn){
        cin>>xh.first>>xh.second;
    }
    sort(xhn.begin(),xhn.end());
    vector<ll> xtbl; xtbl.reserve(N);
    for(const auto& xh:xhn){
        xtbl.push_back(xh.first);
    }
    vector<ll> sub_tbl(N+10,0);

    ll ans=0;
    ll add_val=0;
    ll sub_val=0;
    FOR(i,0,N){
        add_val -= sub_tbl.at(i);

        const auto &d = xhn.at(i);
        ll hp=d.second - add_val;
        if (hp <= 0) continue;
        ll times = (hp + A-1)/A;
        ans += times;
        ll del_val = times * A;
        ll pos = d.first + 2*D;
        auto it = upper_bound(xtbl.begin()+i+1,xtbl.end(),pos);
        //--it;
        ll lim = distance(xtbl.begin(), it);
        // FOR(j,i,lim){
        //     xhn.at(j).second -= del_val;
        // }
        sub_tbl.at(lim) += del_val;
        add_val += del_val;
    }
    cout<<ans<<endl;
    return 0;
}

int main_() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,D,A; cin>>N>>D>>A;
    vector<pair<ll,ll>> xhn(N);
    for(auto&& xh:xhn){
        cin>>xh.first>>xh.second;
    }
    sort(xhn.begin(),xhn.end());
    vector<ll> xtbl; xtbl.reserve(N);
    for(const auto& xh:xhn){
        xtbl.push_back(xh.first);
    }

    ll ans=0;
    FOR(i,0,N){
        const auto &d = xhn.at(i);
        if (d.second <= 0) continue;
        ll times = (d.second + A-1)/A;
        ans += times;
        ll del_val = times * A;
        ll pos = d.first + 2*D;
        auto it = upper_bound(xtbl.begin()+i+1,xtbl.end(),pos);
        //--it;
        ll lim = distance(xtbl.begin(), it);
        FOR(j,i,lim){
            xhn.at(j).second -= del_val;
        }
    }
    cout<<ans<<endl;
    return 0;
}