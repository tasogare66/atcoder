//https://atcoder.jp/contests/joi2016yo/tasks/joi2016yo_e
//E - ゾンビ島 (Zombie Island)
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
  ll danger=0;
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
  std::ifstream in("./test/sample-1.in");
  //std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll N,M,K,S; cin>>N>>M>>K>>S; //Kしはい,S危険
  ll P,Q; cin>>P>>Q; //cost, Qが危険コスト
  unordered_map<ll,ll> ck; //いけないところ
  REP(i,K){
    ll c; cin>>c;
    ck[c]=1;
  }
  WeightedGraph<ll> graph(N+1);
  REP(i,M){
    ll a,b; cin>>a>>b;
    ll cst=ck.count(b)>0?LINF:P;
    graph.at(a).edges.emplace_back(a,b,cst);
    cst=ck.count(a)>0?LINF:P;
    graph.at(b).edges.emplace_back(b,a,cst);
  }

  //bfsで危険をうめていく
  for(auto& p:ck){
    ll c=p.first;
    queue<ll> que;
    vector<int> visited(graph.size());
    que.push(c);
    graph.at(c).danger=S+1;
    visited.at(c)=1;
    while(not que.empty()){
      ll cur=que.front();
      que.pop();

      ll cur_danger = graph.at(cur).danger;
      if (cur_danger <= 0) continue;
      for(auto& e:graph.at(cur).edges){
        auto next = e.to;
        if (visited.at(next)) continue;
        chmax(graph.at(next).danger, cur_danger-1);
        visited.at(next)=true;
        que.push(next);
      }
    }
  }

  auto get_cost = [&](ll to)->ll{
    if (to==1||to==N) return 0; //1,Nは泊まらない
    if (ck.count(to)>0) return LINF;
    if (graph.at(to).danger>0) return Q;
    return P;
  };

  //costいれなおす
  for(auto&& g:graph){
    for(auto&& e:g.edges){
      e.cost = get_cost(e.to);
    }
  }

  //dijkstra
  vector<int> prev;
  auto ans=dijkstra(graph,1,prev);
  cout<<ans.at(N)<<endl;

  return 0;
}