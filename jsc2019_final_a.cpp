//https://atcoder.jp/contests/jsc2019-final/tasks/jsc2019_final_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,M; cin>>N>>M;
    vector<pair<ll,ll>> an(N),bm(M); //weight,pos
    REP(i,N){
        auto&& a = an.at(i);
        a.second = i;
        cin>>a.first;
    }   
    REP(i,M){
        auto&& b = bm.at(i);
        b.second = i;
        cin>>b.first;
    }
    sort(an.begin(),an.end(),greater<ll>());
    sort(bm.begin(),bm.end(),greater<ll>());
    using SumAB = tuple<ll,ll,ll>; //sum,aid,bid
    priority_queue<SumAB> que;
    set<ll,ll> se;
    auto que_pb = [&](ll ia,ll ib){
        make_tupple( ,ia,ib);
        que.push();
    };
    for(ll i=0;i<(max(an.size(),bm.size()));++i){
        const auto& d = que.top();

    }
    return 0;
}