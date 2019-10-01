//dijkstra
//sから各nodeの最短距離と、get_pathでnまでの経路がわかる
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#include "template_graph.cpp"

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
vector<int> get_path(int t, const vector<int>& prev){ //頂点tへの最短路
	vector<int> path;
	for(; t != -1;t=prev[t]){
		path.push_back(t);
	}
	reverse(path.begin(), path.end());
	return path;
}

int main() {
    //aoj_grl_1_a
	//https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
	ll V,E; cin>>V>>E;
	ll r; cin>>r;
    WeightedGraph<ll> graph(V);
	REP(e,E){
		int s,t; cin>>s>>t;
		ll d; cin>>d;
		graph.at(s).edges.emplace_back(t,d);
	}

	vector<int> prev;
	auto result = dijkstra(graph, r, prev);
	for(const auto& d:result){
		if (d>=numeric_limits<ll>::max()) cout<<"INF"<<endl;
		else cout<<d<<endl;
	}
    return 0;
}