//https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_d
//D - 星座探し
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
    ll m; cin>>m;
    vector<pair<ll,ll>> orig(m);
    for(auto&& p:orig){
        cin>>p.first>>p.second;
    }    
    ll n; cin>>n;
    vector<pair<ll,ll>> tbl(n);
    set<pair<ll,ll>> tbl_set;
    for(auto&& p:tbl){
        cin>>p.first>>p.second;
        tbl_set.insert({p});
    }

    vector<pair<ll,ll>> ofs(m-1);
    FOR(i,0,m-1){
        ofs.at(i).first = orig.at(i).first-orig.at(m-1).first;
        ofs.at(i).second = orig.at(i).second-orig.at(m-1).second;
    }
    for(const auto& p:tbl){
        bool found=true;
        for(const auto& o:ofs){
            auto c = p;
            c.first += o.first;
            c.second += o.second;
            auto it=tbl_set.find(c);
            if(it==tbl_set.end()){
                found=false;
                break;
            }
        }
        if(found){
            ll ans_x=p.first-orig.at(m-1).first;
            ll ans_y=p.second-orig.at(m-1).second;
            cout<<ans_x<<" "<<ans_y<<endl;
            return 0;
        }
    }
    assert(0);
    return 0;
}