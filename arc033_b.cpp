//https://atcoder.jp/contests/arc033/tasks/arc033_2
//B - メタ構文変数
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
    ll NA,NB; cin>>NA>>NB;
    vector<ll> ana(NA),bnb(NB);
    map<ll,ll> tbl;
    for(auto&& a:ana){
        cin>>a;
        tbl[a]=1;
    }
    assert(tbl.size()==ana.size());
    ll cnt=0;
    for(auto&& b:bnb){
        cin>>b;
        if(tbl.count(b)) ++cnt;
        tbl[b]=1;
    }
    double ans=(double)cnt/(double)tbl.size();
    cout<<fixed<<std::setprecision(10)<<ans<<endl;
    return 0;
}