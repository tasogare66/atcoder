//https://atcoder.jp/contests/arc005/tasks/arc005_2
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
    std::ifstream in("./test/sample-3.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll x,y; cin>>x>>y;
    string W; cin>>W;
    vector<string> c99(9);
    for(auto&& c:c99){
        cin>>c;
    }

    map<string,pair<ll,ll>> ofs = {
        {"R",{1,0}},
        {"L",{-1,0}},
        {"U",{0,-1}},
        {"D",{0,1}},
        {"RU",{1,-1}},
        {"RD",{1,1}},
        {"LU",{-1,-1}},
        {"LD",{-1,1}},
    };

    string ans;
    auto px=x-1, py=y-1;
    auto v = ofs.at(W);
    REP(i,4){
        auto c = c99.at(py).at(px);
        ans.push_back(c);
        //move
        auto tx = px + v.first;
        auto ty = py + v.second;
        if (tx<0||tx>=9) v.first = -v.first;
        if (ty<0||ty>=9) v.second = -v.second;
        px += v.first;
        py += v.second;
    }
    cout<<ans<<endl;
    return 0;
}