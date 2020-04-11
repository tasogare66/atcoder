//https://atcoder.jp/contests/abc119/tasks/abc119_d
//D - Lazy Faith
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
#if LOCAL&01
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll A,B,Q; cin>>A>>B>>Q;
    vector<ll> sa(A); //sorted
    vector<ll> tb(B); //sorted
    vector<ll> xq(Q);
    for(auto&& s:sa){
        cin>>s;
    }
    for(auto&& t:tb){
        cin>>t;
    }
    for(auto&& x:xq){
        cin>>x;
    }

    auto calc_dist = [&](ll x){
        auto it_s = lower_bound(sa.begin(),sa.end(),x);
        auto it_t = lower_bound(tb.begin(),tb.end(),x);
        auto it_su = upper_bound(sa.begin(),sa.end(),x);
        auto it_tu = upper_bound(tb.begin(),tb.end(),x);
        constexpr ll INF=1e+11;
        ll s[2]={INF,INF};
        ll t[2]={INF,INF};
        if(it_s != sa.end()) s[1]=*it_s-x;
        if(it_t != tb.end()) t[1]=*it_t-x;
        if(it_su != sa.begin()) s[0]=x-*(it_su-1);
        if(it_tu != tb.begin()) t[0]=x-*(it_tu-1);

        ll result=INT64_MAX;
        chmin(result, max(s[1],t[1]));
        chmin(result, max(s[0],t[0]));
        chmin(result, s[0]+t[1]*2);
        chmin(result, s[0]*2+t[1]);
        chmin(result, s[1]+t[0]*2);
        chmin(result, s[1]*2+t[0]);
        assert(result != INT64_MAX);
        return result;
    };

    for(const auto& x:xq){
        auto r = calc_dist(x);
        cout<<r<<endl;
    }

    return 0;
}