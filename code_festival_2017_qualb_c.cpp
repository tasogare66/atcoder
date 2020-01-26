//https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_c
//C - 3 Steps
//2部グラフ判定
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
    int col=-1;
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< node< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

template< typename T >
bool dfs(WeightedGraph<T>& g, int idx, int par, int col) {
    bool ret=true;
    if(g[idx].col == -1) {
        g[idx].col = col;
        for(auto& e:g[idx].edges){
            if(e.to == par) continue;
            ret &= dfs(g, e.to, idx, (col+1)&1);
        }
    }
    if(g[idx].col != col) return false;
    return ret;
}

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,M; cin>>N>>M;
    WeightedGraph<ll> graph(N+1);
    REP(i,M){
        ll A,B; cin>>A>>B;
        graph.at(A).edges.emplace_back(A,B,1);
        graph.at(B).edges.emplace_back(B,A,1);
    }

    ll ans=0;
    bool nibu=dfs(graph, 1, -1, 0);
    if(nibu){
        ll n[2]={};
        FOR(i,1,N+1){
            auto c = graph.at(i).col;
            assert(c!=-1);
            n[c]++;
        }
        ans = n[0]*n[1] - M;
    } else {
        ans = N * (N-1) / 2 - M;
    }
    cout<<ans<<endl;
    return 0;
}