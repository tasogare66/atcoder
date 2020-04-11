//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1127
//Building a Space Station
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

bool solve(){
  ll n; cin>>n;
  if(n<=0) return false;
  struct Posr{
    double x,y,z,r;
  };
  vector<Posr> tbl;
  REP(i,n){
    Posr pr;
    cin>>pr.x>>pr.y>>pr.z>>pr.r;
    tbl.emplace_back(move(pr));
  }
  auto length = [](const Posr& p0, const Posr& p1){
    auto x=p0.x-p1.x;
    auto y=p0.y-p1.y;
    auto z=p0.z-p1.z;
    return sqrt(x*x+y*y+z*z);
  };

  WeightedGraph<double> graph(n);
  FOR(i,0,tbl.size()){
    FOR(j,i+1,tbl.size()){
      const auto& p0=tbl.at(i);
      const auto& p1=tbl.at(j);
      auto len = length(p0,p1);
      auto cost=max<double>(0,len-p0.r-p1.r);
      graph.at(i).edges.emplace_back(i,j,cost);
      graph.at(j).edges.emplace_back(j,i,cost);
    }
  }

  auto mst=prim(graph);
  cout<<fixed<<std::setprecision(3)<<mst.first<<endl;

  return true;
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
  while(solve()){
  }
  return 0;
}