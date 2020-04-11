//https://atcoder.jp/contests/abc073/tasks/abc073_d
//D - joisino's travel
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
    ll N,M,R; cin>>N>>M>>R;
    vector<int> rr(R);
    for(auto&& r:rr){
        cin>>r;
    }
    sort(rr.begin(),rr.end());
    WeightedGraph<ll> graph(N+1);
    REP(i,M){
        ll a,b,c;
        cin>>a>>b>>c;
        graph.at(a).edges.emplace_back(b,c);
        graph.at(b).edges.emplace_back(a,c);
    }

    unordered_map<ll,vector<ll>> rtbl;
    FOR(i,0,rr.size()){
        auto r=rr.at(i);
	    vector<int> prev;
	    auto result = dijkstra(graph, r, prev);
        rtbl[r] = move(result);
    }

    ll ans=INT64_MAX;
    do{
        ll result=0;
        FOR(i,0,rr.size()-1){
            auto st=rr.at(i);
            auto gl=rr.at(i+1);
            result += rtbl[st].at(gl);
            if(result<0)assert(0);
        }
        ans=min(result,ans);
    }while(next_permutation(rr.begin(),rr.end()));
    cout<<ans<<endl;
    return 0;
}