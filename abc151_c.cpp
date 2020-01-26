//https://atcoder.jp/contests/abc151/tasks/abc151_c
//C - Welcome to AtCoder
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
    ll N, M; cin>>N>>M;
    vector<pair<int,string>> psm(M);
    for(auto&& ps:psm){
        cin>>ps.first>>ps.second;
    }
    struct Info{
        ll wa_tmp=0;
        ll ac=0, wa=0;
    };
    map<int,Info> tbl;
    for(const auto& ps:psm){
        ll n=ps.first;
        if(ps.second=="WA"){
            if (tbl[n].ac){
            }else{
                tbl[n].wa_tmp++;
            }
        }else{
            if (!tbl[n].ac){
                tbl[n].ac=1;
                tbl[n].wa=tbl[n].wa_tmp;
            }
        }
    }
    ll ans_ac=0, ans_wa=0;
    for(const auto& t:tbl){
        ans_ac += t.second.ac;
        ans_wa += t.second.wa;
    }
    cout<<ans_ac<<" "<<ans_wa<<endl;
    return 0;
}