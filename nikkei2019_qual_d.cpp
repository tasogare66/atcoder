//https://atcoder.jp/contests/nikkei2019-qual/tasks/nikkei2019_qual_d
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
    for (int i = 1; i < n; ++i) //1start
        if (state[i] == State::NEW && !dfs(i)) return {-1};
    std::reverse(res.begin(), res.end());
    return res;
}

struct Node{
    vector<ll> iri;
    ll topo=-1;
};

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll n,m; cin>>n>>m;
    Graph graph(n+1);
    vector<Node> nodes(n+1);
    FOR(i,1,(n+m-1+1)){
        ll a,b; cin>>a>>b;
        graph.at(a).emplace_back(a,b,0);
        nodes.at(b).iri.push_back(a);
    }
    auto ord=tsort(graph);
    FOR(i,0,ord.size()){
        nodes[ord.at(i)].topo=i;
        //cout<<ord.at(i)<<endl;
    }

    //topologyがしたのedgeを出力していく
    for(ll i=1;i<nodes.size();++i){
        const auto& cn = nodes[i];
        vector<pair<ll,ll>> tmp;
        for(auto iri_n: cn.iri){
             tmp.push_back({nodes[iri_n].topo,iri_n});
        }
        sort(tmp.begin(),tmp.end(),[](auto& a,auto& b){ return a.first > b.first;}); //topology降順にsort
        
        cout<<(tmp.size()<=0?0:tmp.begin()->second)<<endl;
    }

    return 0;
}