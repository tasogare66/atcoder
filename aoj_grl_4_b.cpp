//
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

struct Edge{
    ll st; //start
    ll tr; //end
    ll weight;
	Edge(ll s, ll t, ll w) : st(s), tr(t), weight(w) {}
	Edge() : Edge(0, 0, 0) {}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
//topological sort の一つを得る、１つの入力に対して複数の解答がる。
std::vector<int> tsort(const Graph &g) {
    int n = g.size();
    enum class State { NEW, ACTIVE, FINISHED };
    std::vector<int> res;
    vector <State> state(n, State::NEW);
    static const std::function<bool(int)> dfs = [&](int v) {
        state[v] = State::ACTIVE;
        for (auto &e : g[v]) {
            int w = e.tr;
            if (state[w] == State::ACTIVE) return false;
            else if (state[w] == State::NEW) if (!dfs(w)) return false;
        }
        state[v] = State::FINISHED;
        res.push_back(v);
        return true;
    };
    for (int i = 0; i < n; ++i)
        if (state[i] == State::NEW && !dfs(i)) return {-1};
    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    ll vn, en; cin>>vn>>en; //頂点数,辺の数
    Graph graph(vn);
    REP(i,en){
        ll s,t; cin>>s>>t;
        graph.at(s).emplace_back(s,t,0);
    }

    auto ord = tsort(graph);
    for(const auto& o:ord){
        cout<<o<<endl;
    }

    return 0;
}