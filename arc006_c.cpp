//https://atcoder.jp/contests/arc006/tasks/arc006_3
//C - 積み重ね
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
    ll N; cin>>N;
    vector<ll> wn(N);
    for(auto&& w:wn){
        cin>>w;
    }
    //貪欲
    map<ll,int> tbl;
    for(const auto& w:wn){
        auto it = tbl.lower_bound(w);
        if(it != tbl.end()){
            tbl.erase(it); //erase重い?
        }
        tbl[w]=0;
    }
    cout<<tbl.size()<<endl;
    return 0;
}