//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja
//単一始点最短経路
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
const ll LINF = 0x1fffffffffffffff;
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
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< node< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;
//s start node
//return 各nodeへの最短の距離が入る,numeric_limits<T>::max()の場合、到達できない
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
  ll V,E; cin>>V>>E;
  ll r; cin>>r;
  WeightedGraph<ll> graph(V);
  REP(i,E){
    ll s,t,d; cin>>s>>t>>d;
    graph.at(s).edges.emplace_back(t,d);
  }

  vector<int> prev;
  auto ans = dijkstra(graph, r, prev);
  FOR(i,0,ans.size()){
    ll v=ans.at(i);
    if (v==numeric_limits<ll>::max()){
      cout<<"INF"<<endl;
    }else cout<<v<<endl;
  }

  return 0;
}