//https://atcoder.jp/contests/abc035/tasks/abc035_d
//D - トレジャーハント
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
//return 各nodeへの最短の距離が入る
template< typename T >
vector< T > dijkstra(const WeightedGraph< T > &g, int s, vector<int>& prev) {
	const auto INF = numeric_limits<T>::max();
	vector<T> dist(g.size(), INF);
	prev.assign(g.size(),-1);

	using Pi = pair<T, int>; //dist,node id
	priority_queue<Pi, vector<Pi>, greater<Pi>> que;
	dist[s] = 0;
	que.emplace(dist[s], s);
	while(!que.empty()) {
		T cost;
		int idx; //node id
		tie(cost, idx) = que.top();
		que.pop();
		if(dist[idx] < cost)
			continue;
		for(auto &e : g[idx].edges) {
			auto next_cost = cost + e.cost;
			if(dist[e.to] <= next_cost)
				continue;
			dist[e.to] = next_cost;
			prev[e.to] = idx;
			que.emplace(dist[e.to], e.to);
		}
	}
	return dist;
}

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,M,T; cin>>N>>M>>T;
    vector<ll> an(N+1);
    FOR(i,1,N+1){
        cin>>an.at(i);
    }
    WeightedGraph<ll> graph_s(N+1);
    WeightedGraph<ll> graph_g(N+1);
    REP(i,M){
        ll a,b,c; cin>>a>>b>>c;
        graph_s.at(a).edges.emplace_back(b,c);
        graph_g.at(b).edges.emplace_back(a,c);
    }

    vector<int> prev_s, prev_g;
    auto res_s = dijkstra(graph_s, 1, prev_s);
    auto res_g = dijkstra(graph_g, 1, prev_g);
    ll ans=0;
    FOR(i,1,N+1){
        ll c_s = res_s.at(i);
        ll c_g = res_g.at(i);
        if (c_s>=numeric_limits<ll>::max() || c_g>=numeric_limits<ll>::max()){
            continue;
        }
        ll c = c_s + c_g;
        ans=max((T-c)*an.at(i),ans);
    }
    cout<<ans<<endl;
    return 0;
}