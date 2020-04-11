//https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_e
//E - イルミネーション (Illumination)
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
    ll W, H; cin>>W>>H;
    vector<vector<ll>> m_whs(H+2,vector<ll>(W+2,0));
    FOR(y,1,H+1){
        FOR(x,1,W+1){
            cin>>m_whs.at(y).at(x);
        }
    }

    using pos=pair<ll,ll>; //x,y
    pos ofs[][6]={
        {{1,0},{-1,0}, {0,1},{-1,1},{0,-1},{-1,-1}}, //eve
        {{1,0},{-1,0}, {0,1},{1,1},{0,-1},{1,-1}}, //odd
    };    

    auto get_mh =[&](const pos& p)->ll*{
        size_t x=p.first;
        size_t y=p.second;
        if (x>=m_whs[0].size() || y>=m_whs.size())return nullptr;
        return &m_whs.at(y).at(x);
    };

    ll ans=0;
    auto check_arround = [&](const pos& p){
        for(const auto& o:ofs[p.second%2]){
            auto np = p;
            np.first += o.first;
            np.second += o.second;
            //dump(np);
            auto* wh = get_mh(np);
            if(wh && *wh==1) ++ans;
        }
    };
    //check_arround({3,1}); dump(ans); return 0;

    queue<pos> que;
    que.push({0,0});
    check_arround({0,0});
    *get_mh({0,0})=2;
    while(not que.empty()){
        auto t = que.front();
        que.pop();
        for(const auto& o:ofs[t.second%2]){
            auto np = t;
            np.first += o.first;
            np.second += o.second;
            auto* wh = get_mh(np);
            if(not wh || *wh!=0)continue;
            dump(np);
            check_arround(np);
            *wh=2;
            que.push(np);
        }
    }
    dump(m_whs);
    cout<<ans<<endl;
    return 0;
}