//https://atcoder.jp/contests/joi2020yo2/tasks/joi2020_yo2_b
//B - いちご (Strawberry)
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
    struct info {
        ll a, t;
        bool flag=false;
    };
    vector<info> atn(N);
    for(auto&& at:atn){
        cin>>at.a>>at.t;
    }    
    sort(atn.begin(),atn.end(),[](const auto&a,const auto&b){return a.a<b.a;});
    FOR(i,0,N){
        auto& d= atn.at(i);
        if(d.a>=d.t) d.flag=true;
    }
    ll len2=atn.back().a*2;
    //帰り
    vector<info> backway;
    for(ll i=N-1;i>=0;--i){
        auto d = atn.at(i);
        d.a=(len2-d.a);
        if(!d.flag) backway.emplace_back(move(d));
    }
    if(backway.empty()){
        cout<<len2<<endl;
        return 0;
    }

    ll ans=atn.back().a;
    ll p=atn.back().a;
    for(const auto& at:backway){
        ans += at.a-p;
        p = at.a;
        ans = max(ans, at.t);
    }
    ans += (len2-backway.back().a);
    cout<<ans<<endl;
    return 0;
}