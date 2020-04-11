//https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_e
//E - チーズ (Cheese)
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
    ll H,W,N; cin>>H>>W>>N;
    vector<string> map(H);
    for(auto& s:map){
        cin>>s;
    }    
    using pos=pair<ll,ll>;//x,y
    vector<pos> lst(N+1);
    FOR(y,0,H){
        FOR(x,0,W){
            auto c=map.at(y).at(x);
            if(c=='X')continue;
            if(c=='.')continue;
            if(c=='S'){
                lst.at(0)={x,y};
            }else{
                auto no=c-'0';
                lst.at(no)={x,y};
            }
        }
    }

    pos ofs[]={
        {1,0},{-1,0},{0,-1},{0,1}
    };    
    auto available = [&](ll x, ll y)->bool{
        if (x<0||x>=W)return false;
        if (y<0||y>=H)return false;
        auto c=map.at(y).at(x);
        if(c=='X') return false;
        return true;
    };
    auto bfs = [&](pos s, pos e)->ll{
        vector<vector<ll>> dist(H,vector<ll>(W,-1));
        queue<pos> que;
        que.push(s);
        dist.at(s.second).at(s.first)=0;
        while(not que.empty()){
            auto t = que.front();
            ll d=dist.at(t.second).at(t.first);
            if(t.first==e.first&& t.second==e.second) return d;
            que.pop();
            for(const auto& o:ofs){
                auto np = t;
                np.first += o.first;
                np.second += o.second;
                if(not available(np.first,np.second))continue;
                if(dist.at(np.second).at(np.first)>=0)continue;
                dist.at(np.second).at(np.first)=d+1;
                que.push(np);
            }
        }
        assert(0);
        return 0;
    };

    ll ans=0;
    FOR(i,0,lst.size()-1){
        auto s=lst.at(i);
        auto e=lst.at(i+1);
        ans += bfs(s,e);
    }
    cout<<ans<<endl;

    return 0;
}