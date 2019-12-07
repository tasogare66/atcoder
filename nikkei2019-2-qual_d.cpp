//https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_d
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
vector<int> get_path(int t, const vector<int>& prev){ //頂点tへの最短路
	vector<int> path;
	for(; t != -1;t=prev[t]){
		path.push_back(t);
	}
	reverse(path.begin(), path.end());
	return path;
}

struct Info{
    ll L,R,C;
};

//i-1 -> iのcost0 のedgeを追加する。
int main() {
    ll N, M; cin>>N>>M; 
    vector<Info> inp(M);
    for(auto&& i:inp){
        cin>>i.L>>i.R>>i.C;
    }

    WeightedGraph<ll> graph(N+1);
    //i+1 -> iのcost0 のedgeを追加する。
    FOR(i,2,N+1){
        ll s=i;
        ll e=i-1;
        graph.at(s).edges.emplace_back(e,0);
    }
    //L->Rの edgeを追加する
    for(const auto& i: inp){
        graph.at(i.L).edges.emplace_back(i.R,i.C);
        graph.at(i.R).edges.emplace_back(i.L,i.C);
    }

	vector<int> prev;
	auto result = dijkstra(graph, 1, prev);
    auto ans = result[N];
    if (ans >=numeric_limits<ll>::max()) ans=-1;
    cout<<ans<<endl;;
    return 0;
}

int _main() {
    ll N, M; cin>>N>>M; 
    vector<Info> inp(M);
    for(auto&& i:inp){
        cin>>i.L>>i.R>>i.C;
    }
    sort(inp.begin(),inp.end(),[](const auto&a,const auto&b){
        return a.C<b.C;
    });
    using pi=pair<ll,ll>;
    map<pi,ll> tbl;
    for(const auto& i:inp){
        ll l=i.L;
        ll r=i.R;
        for(ll s=l;s<r;++s){
            for(ll e=s+1;e<=r;++e){
				pi c = {s, e};
				if(tbl.count(c) <= 0) {
					tbl[c] = i.C;
				}
			}
		}
    }

    WeightedGraph<ll> graph(N+1);
    for(const auto& t:tbl){
        ll s=t.first.first;
        ll e=t.first.second;
        ll c=t.second;
        graph.at(s).edges.emplace_back(e,c);
		graph.at(e).edges.emplace_back(s, c);
	}

	vector<int> prev;
	auto result = dijkstra(graph, 1, prev);
    auto ans = result[N];
    if (ans >=numeric_limits<ll>::max()) ans=-1;
    cout<<ans<<endl;;

    return 0;
}