//https://atcoder.jp/contests/abc126/tasks/abc126_d
//D - Even Relation
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
    ll color=-1;
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< node< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

int main() {
    ll N; cin>>N;
    WeightedGraph<ll> graph(N+1); //木
    REP(e,N){
        ll u,v,w; cin>>u>>v>>w;
        graph.at(u).edges.emplace_back(v,w);
        graph.at(v).edges.emplace_back(u,w);
    }
    graph.at(1).color=0;
    function<void(ll)> dfs = [&](ll n){
        auto& nd=graph.at(n);
        for(auto e: nd.edges){
            auto& nx = graph.at(e.to);
            if(nx.color != -1) continue;
            nx.color = e.cost%2==0?nd.color:(nd.color+1)&1;
            dfs(e.to);
        }        
    };
    dfs(1);
    FOR(i,1,N+1){
        cout<<graph.at(i).color<<endl;
    }
    return 0;
}