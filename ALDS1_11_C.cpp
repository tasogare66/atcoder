//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=ja
//幅優先探索
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
    ll dist=-1;
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
    ll n; cin>>n;
    WeightedGraph<ll> graph(n+1);
    FOR(i,1,n+1){
        ll u,k; cin>>u>>k;
        REP(j,k){
            ll v; cin>>v;
            graph.at(u).edges.emplace_back(v,1);
        }
    }

    //bfs
    queue<ll> st;
    st.push(1);
    graph.at(1).dist=0;
    while(not st.empty()){
        auto cn = st.front();
        st.pop();
        auto& node = graph.at(cn);
        for(const auto& nn:node.edges){
            if(graph.at(nn).dist>=0) continue;
            graph.at(nn).dist = node.dist + 1;
            st.push(nn.to);
        }
    }

    FOR(i,1,n+1){
        cout<<i<<" "<<graph.at(i).dist<<endl;
    }
    return 0;
}