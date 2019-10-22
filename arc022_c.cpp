//https://atcoder.jp/contests/arc022/tasks/arc022_3
//C - ロミオとジュリエット
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

template< typename T >
struct edge {
	int src, to;
	T cost;
	edge(int _to, T _cost) : src(-1), to(_to), cost(_cost) {}
	edge(int _src, int _to, T _cost) : src(_src), to(_to), cost(_cost) {}
	edge &operator=(const int &x) {
		to = x;
		return *this;
	}
	operator int() const { return to; }
};

template< typename T>
struct node {
	vector<edge<T>> edges;
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< node< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

//木の直径,aoj_grl_5_a
template< typename T >
pair< T, int > tree_dfs(const WeightedGraph< T > &g, int idx, int par) {
    pair< T, int > ret(0, idx);
    for(auto &e : g[idx].edges) {
        if(e.to == par) continue;
        auto cost = tree_dfs(g, e.to, idx);
        cost.first += e.cost;
        ret = max(ret, cost);
    } 
    return ret;
}

//st_idx探索開始のidx
template< typename T >
auto tree_diameter(const WeightedGraph< T > &g, int st_idx) {
    auto p = tree_dfs(g, st_idx, -1); //st_idxから最遠頂点
    auto q = tree_dfs(g, p.second, -1); //上記の最遠頂点からの最遠頂点
    //return (q.first);
    return make_pair(p.second,q.second);
}

int main() {
    ll N; cin>>N;    
    WeightedGraph<ll> graph(N+1);
    REP(i,N-1){
        ll a,b; cin>>a>>b;
        graph.at(a).edges.emplace_back(a,b,1);
        graph.at(b).edges.emplace_back(b,a,1);
    }

    auto ans = tree_diameter(graph, 1);
    cout<<ans.first<<" "<<ans.second<<endl;

    return 0;
}