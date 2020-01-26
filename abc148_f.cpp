//https://atcoder.jp/contests/abc148/tasks/abc148_f
//F - Playing Tag on Tree
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
    ll dist[2]={};
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
pair< T, int > tree_dfs(WeightedGraph< T > &g, int idx, int par, int fmsm=0) {
    assert(fmsm==0||fmsm==1);
    pair< T, int > ret(0, idx);
    for(auto &e : g[idx].edges) {
        if(e.to == par) continue;
        g[e.to].dist[fmsm]=g[idx].dist[fmsm]+e.cost; //...
        auto cost = tree_dfs(g, e.to, idx, fmsm);
        cost.first += e.cost;
        ret = max(ret, cost);
    } 
    return ret;
}

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,u,v; cin>>N>>u>>v;    
    WeightedGraph<ll> graph(N+1);
    FOR(i,0,N){
        ll a,b; cin>>a>>b;
        graph.at(a).edges.emplace_back(a,b,1);
        graph.at(b).edges.emplace_back(b,a,1);
    }
    auto p = tree_dfs(graph, u, -1, 0);
    auto q = tree_dfs(graph, v, -1, 1);
    ll ans=0;
    FOR(i,1,N+1){
        const auto &g = graph.at(i);
        if (g.dist[0]<g.dist[1]) {
            chmax(ans,g.dist[1]-1);
            dump(i,g.dist[0],g.dist[1]);
        }
    }
    cout<<ans<<endl;
    return 0;
}