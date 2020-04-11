//https://atcoder.jp/contests/abc065/tasks/arc076_b
//D - Built?
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

template< typename T >
bool operator<(const edge<T> &e, const edge<T> &f) { return e.cost > f.cost; }
template< typename T >
std::pair<T, Edges<T>> prim(const WeightedGraph<T> &g, int r = 0) {
  Edges<T> edges;
  T total = T();
  std::vector<int> vis(g.size());
  std::priority_queue<edge<T>> q;
  q.emplace(-1, r, 0);
  while (q.size()) {
    auto e = q.top();
    q.pop();
    if (vis[e.to]) continue;
    vis[e.to] = true;
    total += e.cost;
    if (e.src != -1) edges.emplace_back(e);
    for (auto &f : g[e.to].edges)
      if (!vis[f.to]) q.emplace(f);
  }
  return std::make_pair(total, edges);
}

int main() {
  ll N; cin>>N;
  using idp = pair<ll,ll>;
  vector<idp> xtbl, ytbl;
  FOR(i,0,N){
    ll x,y; cin>>x>>y;
    xtbl.push_back({i,x});
    ytbl.push_back({i,y});
  }
  sort(xtbl.begin(),xtbl.end(),[](auto& a, auto& b){ return a.second<b.second;});
  sort(ytbl.begin(),ytbl.end(),[](auto& a, auto& b){ return a.second<b.second;});

  WeightedGraph<ll> graph(N);
  FOR(i,0,N-1){
    const auto& s=xtbl.at(i);
    const auto& t=xtbl.at(i+1);
    graph.at(s.first).edges.emplace_back(s.first, t.first, abs(s.second-t.second));
    graph.at(t.first).edges.emplace_back(t.first, s.first, abs(s.second-t.second));
  }
  FOR(i,0,N-1){
    const auto& s=ytbl.at(i);
    const auto& t=ytbl.at(i+1);
    graph.at(s.first).edges.emplace_back(s.first, t.first, abs(s.second-t.second));
    graph.at(t.first).edges.emplace_back(t.first, s.first, abs(s.second-t.second));
  }

  auto mst = prim(graph);
  cout<<mst.first<<endl;

  return 0;
}