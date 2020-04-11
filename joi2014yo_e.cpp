//https://atcoder.jp/contests/joi2014yo/tasks/joi2014yo_e
//E - タクシー (Taxis)
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

int main() {
#if LOCAL&01
  //std::ifstream in("./test/sample-1.in");
  std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll N,K; cin>>N>>K;
  vector<pair<ll,ll>> crn(N);
  for(auto&& p:crn) cin>>p.first>>p.second;
  WeightedGraph<ll> graph(N+1);
  REP(i,K){
    ll a,b; cin>>a>>b;
    graph.at(a).edges.emplace_back(b,LINF);
    graph.at(b).edges.emplace_back(a,LINF);
  }

  WeightedGraph<ll> g2(N+1);
  REP(i,N){
    ll from=i+1;
    ll cost,lim; tie(cost,lim)=crn.at(i);
#if 0
    //dfsで全部
    vector<bool> visited(N+1);
    auto dfs = [&](auto&& self, ll p, ll v){
      if(v>=lim){
        return;
      }
      for(auto&& e:graph.at(p).edges){
        if (visited.at(e.to)) continue;
        g2.at(from).edges.emplace_back(e.to, cost);
        visited[e.to]=true;
        dump(from,p,cost);
        self(self, e.to, v+1); //訪問すみとか関係ないよ
      }
    };
    visited[from]=true;
    dfs(dfs, from, 0);
#else
    //bfsでedgeをはる
    queue<ll> que;
    que.push(from);
    vector<ll> dist(N+1);
    dist.at(from)=lim;
    while(not que.empty()){
      ll cur = que.front();
      ll cur_dist = dist[cur];
      que.pop();

      for(const auto& e:graph.at(cur).edges){
        if (dist[e.to]!=0)continue;
        dist.at(e.to) = cur_dist - 1;
        if (from!=e.to) g2.at(from).edges.emplace_back(e.to, cost);
        if (cur_dist - 1 > 0){
          que.push(e.to);
        }
      }
    }
#endif
  }

  vector<int> prev;
  auto ans = dijkstra(g2,1,prev);
  cout<<ans.at(N)<<endl;

  return 0; 
}