//https://atcoder.jp/contests/abc007/tasks/abc007_3
//C - 幅優先探索
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
 //地図の2重配列とって、そこに距離を書いていったほうがよいか。
int main() {
    ll R,C; cin>>R>>C;
    ll sy,sx; cin>>sy>>sx; --sy,--sx;    
    ll gy,gx; cin>>gy>>gx; --gy,--gx;
    vector<string> crc(R);
    for(auto&& cr:crc){
        cin>>cr;
    }
    //bfs
    using pos = pair<ll,ll>; //y,x
    auto available = [&](const pos& p){
        return (crc.at(p.first).at(p.second) == '.');
    };
    pos ofs[]={
        {1,0},{-1,0},{0,-1},{0,1}
    };
    queue<pair<pos,ll>> que;
    set<pos> visited;
    que.push({{sy,sx},0});
    visited.insert({sy,sx});
    ll ans=0;
    while(not que.empty()){
        auto pd = que.front();
        auto p = pd.first;
        if(p.first==gy&&p.second==gx){
            ans=pd.second;
            break;
        }
        que.pop();
        for(const auto& d:ofs){
            pos np = {p.first+d.first, p.second+d.second};
            if (not available(np)) continue;
            if (visited.count(np)>0) continue;
            visited.insert(np);
            que.push({np,pd.second+1});
        }
    }
    cout<<ans<<endl;

    return 0;
}