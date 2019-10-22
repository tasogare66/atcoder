//https://atcoder.jp/contests/abc061/tasks/abc061_d
//D - Score Attack
//bellman_ford, costを負値でいれて最短経路を探索
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
//s start node
//return 各nodeへの最短の距離, numeric_limits< T >::max() と等しい場合INF(=到達できない)
template< typename T >
vector< T > bellman_ford(const Edges< T > &edges, int V, int s, vector<bool>& negative) {
    const auto INF = numeric_limits< T >::max();
    vector< T > dist(V, INF);
    dist[s] = 0;
    //辺の緩和を反復
    for(int i = 0; i < V - 1; i++) {
        for(auto &e : edges) {
            if(dist[e.src] == INF) continue;
            dist[e.to] = min(dist[e.to], dist[e.src] + e.cost);
        }
    }
    //負の重みの閉路がないかチェック
    //vector<bool> negative(V,false);
    negative.assign(V,false);
    for (ll n=0;n<V;n++){
        for(auto &e : edges) {
            if(dist[e.src] == INF) continue;
            if(dist[e.src] + e.cost < dist[e.to]) negative.at(e.to)=true;
            if(negative.at(e.src)) negative.at(e.to)=true;
        }
    }
    return dist;
}

int main() {
#if LOCAL&01
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,M; cin>>N>>M;
    Edges<ll> edges;
    FOR(e,1,M+1){
        ll a,b,c; cin>>a>>b>>c;
        edges.emplace_back(a,b,-c);
    }
    vector<bool> negative;
    auto result = bellman_ford(edges,N+1,1,negative);
    if (negative.at(N)) {
        cout<<"inf"<<endl;
    } else {
        cout<<-result.at(N)<<endl;
    }
    return 0;
}