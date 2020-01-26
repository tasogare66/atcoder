//https://atcoder.jp/contests/dp/tasks/dp_g
//G - Longest Path
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

struct Edge {
    ll st,tr;
    Edge(ll s, ll t)
        : st(s), tr(t)
    {}
};
struct Node{
    vector<Edge> edges;
    ll cost=0;
};
using Graph = vector<Node>;

//各nodeをdfs
vector<ll> tsort_tarjan(Graph& g){
    auto num = g.size();
    enum class State { NEW, ACTIVE, FINISHED };
    vector<State> state(num, State::NEW); 
    vector<ll> res; res.reserve(num);
    function<bool(int)> dfs = [&](ll v){
        state[v]=State::ACTIVE;
        for(const auto& e : g[v].edges){
            auto w = e.tr; //接続するnodeをdfsしていく
            if (state[w] == State::ACTIVE) return false;
            else if (state[w] == State::NEW) if (!dfs(w)) return false;
        }
        state[v]=State::FINISHED;
        res.push_back(v);
        //ここで処理すると逆順に処理できる
        return true;
    };
    for (ll n=0;n<num;++n) {
        if(state[n]==State::NEW && !dfs(n)) return {}; //空を返す
    }
    std::reverse(res.begin(),res.end());
    return res;
}

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,M; cin>>N>>M;
    Graph graph(N+1);
    REP(i,M){
        ll x,y; cin>>x>>y;
        graph.at(x).edges.emplace_back(x,y);
    }
    auto ord = tsort_tarjan(graph);
    dump(ord);
    for(const auto& o:ord){
        //cout<<o<<endl;
        const auto& n=graph.at(o);
        for(const auto&e: n.edges){
            chmax(graph.at(e.tr).cost,n.cost+1); 
        }
    }
    ll ans=0;
    for(const auto& o:ord){
        chmax(ans,graph.at(o).cost);
    }
    cout<<ans<<endl;
    return 0;
}