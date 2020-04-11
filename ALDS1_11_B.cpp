//https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_11_B
//深さ優先探索
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
    ll d=0,f=0;
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< node< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

int main() {
    ll n; cin>>n;
    WeightedGraph<ll> graph(n+1);
    FOR(i,1,n+1){
        ll u, k; cin>>u>>k;
        FOR(j,0,k){
            ll v; cin>>v;
            graph[i].edges.emplace_back(u,v,1);
        }
    }

    ll counter=1;
    function<void(ll)> dfs = [&](ll id){
        auto& node=graph.at(id);
        if (node.d!=0)return; //訪問済
        node.d=counter++;
        for(const auto& e :graph.at(id).edges){
            dfs(e);
        }
        node.f=counter++;
    };

    FOR(i,1,n+1){
        dfs(i);
    }

    FOR(i,1,n+1){
        const auto& node=graph.at(i);
        cout<<i<<" "<<node.d<<" "<<node.f<<endl;
    }

    return 0;
}