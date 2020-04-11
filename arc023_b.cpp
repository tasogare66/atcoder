//https://atcoder.jp/contests/arc023/tasks/arc023_2
//B - 謎の人物X
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
    ll R,C,D; cin>>R>>C>>D;
    vector<vector<ll>> arc(R,vector<ll>(C));    
    struct Dat{
        ll x,y;
        ll val;
    };
    vector<Dat> tbl;
    tbl.reserve(R*C);
    REP(y,R){
        REP(x,C){
            ll val; cin>>val;
            arc.at(y).at(x)=val;
            Dat d;
            d.x = x;
            d.y = y;
            d.val = val;
            tbl.push_back(d);
        }
    }
    sort(tbl.begin(),tbl.end(),[](const auto& a,const auto& b){return a.val>b.val;});
    auto check_reach = [&](const auto& d){
        ll dist=d.x+d.y;
        if(dist <= D){
            return(dist%2==D%2);
        }
        return false;
    };
    for(const auto&t:tbl){//到達できるか
        if(check_reach(t)){
            cout<<t.val<<endl;
            return 0;
        }
    }
    assert(0);

    return 0;
}