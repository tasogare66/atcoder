//https://atcoder.jp/contests/joisc2010/tasks/joisc2010_finals
//finals - 本選会場 (Finals)
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
#if LOCAL&01
  //std::ifstream in("./test/sample-1.in");
  std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll N,M,K; cin>>N>>M>>K;
  WeightedGraph<ll> graph(N+1);
  REP(i,M){
    ll a,b,c; cin>>a>>b>>c;
    graph.at(a).edges.emplace_back(a,b,c);
    graph.at(b).edges.emplace_back(b,a,c);
  }

  auto mst = prim(graph,1);
  dump(mst.first);
  for(const auto& e: mst.second){
    dump(e.src, e.to, e.cost);
  }
  auto&& edges = mst.second;
  sort(edges.begin(), edges.end(), [](const auto& a, const auto& b){ return a.cost<b.cost;});
  ll ans = 0;
  REP(i,N-K){
    ans += edges.at(i).cost;
  }
  //if(N==K)ans=0;
  cout<<ans<<endl;

  return 0;
}