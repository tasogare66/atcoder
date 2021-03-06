//https://atcoder.jp/contests/agc043/tasks/agc043_a
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
  ll H,W; cin>>H>>W;
  vector<string> shw(H);
  for(auto&& sw:shw) cin>>sw;

  auto cost1 = [&](ll ix,ll iy)->ll{
    //-1いけない,0 or 1
    ll ret=-1;
    if(ix<0) return ret;
    if(iy<0) return ret;
    if(ix>=W) return ret;
    if(iy>=H) return ret;
    if(shw.at(iy).at(ix)=='#') return 1;
    return 0;
  };
  auto getid = [&](ll ix, ll iy){
    return iy*W + ix;
  };

  WeightedGraph<ll> graph(H*W);
  REP(y,H){
    REP(x,W){
      auto src = getid(x,y);
      {
        auto to = getid(x+1,y);
        auto cst = cost1(x+1,y);
        if(cst>=0){
          graph.at(src).edges.emplace_back(src,to,cst);
        }
      }
      {
        auto to = getid(x,y+1);
        auto cst = cost1(x,y+1);
        if(cst>=0){
          graph.at(src).edges.emplace_back(src,to,cst);
        }
      }
    }
  }

	vector<int> prev;
  auto result = dijkstra(graph,0,prev);
  ll ans=result.at(H*W-1);
  if(shw.at(0).at(0)=='#')++ans;
  cout<<ans<<endl;

  return 0;
}