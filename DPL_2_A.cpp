//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A&lang=ja
//DPL_2_A
//巡回セールスマン問題,Traveling Salesman Problem
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
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

int main() {
#if LOCAL&01
  std::ifstream in("./test/sample-1.in");
  //std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll V,E; cin>>V>>E;
  WeightedGraph<ll> graph(V);
  REP(i,E){
    ll s,t,d; cin>>s>>t>>d;
    graph.at(s).edges.emplace_back(t,d);
  }
  ll bit_max=1LL<<V;
  ll INF=2LL<<60;
  vector<vector<ll>> dp(V,vector<ll>(bit_max,INF));
  dp[0][0]=0;//0からスタート
  // FOR(i,0,V){
  //   dp.at(i).at(0)=0;
  // }
  FOR(m,0,bit_max){
    FOR(i,0,V){
      for(const auto&e:graph.at(i).edges){
        ll next_m = m|(1LL<<e.to);
        if(next_m==m) continue;
        chmin(dp[e.to][next_m], dp[i][m]+e.cost);
      }
    }
  }
  dump(dp);
  // ll ans=INF;
  // REP(i,V){
  //   chmin(ans,dp[i][bit_max-1]);
  // }
  ll ans=dp[0][bit_max-1]; //0ゴールの値
  if (ans>=INF) ans=-1;
  cout<<ans<<endl;
  return 0;
}