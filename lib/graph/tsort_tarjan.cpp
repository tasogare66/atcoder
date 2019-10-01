//トポロジカルソート,tarjan
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

struct Edge {
    ll st,tr;
    Edge(ll s, ll t)
        : st(s), tr(t)
    {}
};
struct Node{
    vector<Edge> edges;
};
using Graph = vector<Node>;

//各nodeをdfs
vector<ll> tsort_tarjan(Graph& g){
    auto num = g.size();
    enum class State { NEW, ACTIVE, FINISHED };
    vector<State> state(num, State::NEW); 
    vector<ll> res(num);
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
    //aoj_grl_4_b
    ll vn, en; cin>>vn>>en; //頂点数,辺の数
    Graph graph(vn);
    REP(i,en){
        ll s,t; cin>>s>>t;
        graph.at(s).edges.emplace_back(s,t);
    }

    auto ord = tsort_tarjan(graph);
    for(const auto& o:ord){
        cout<<o<<endl;
    }

    return 0;
}