//https://atcoder.jp/contests/arc005/tasks/arc005_3
//C - 器物損壊！高橋君
//0-1bfs
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

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
    vector<string> imap(H);
    for(auto&& s:imap){
        cin>>s;
    }
    auto calc_idx = [&](ll ix,ll iy){
        return iy*W+ix;
    };
    auto get_map = [&](ll ix,ll iy){
        return imap.at(iy).at(ix);
    };
    auto check_inside = [&](ll ix, ll iy){
        return (ix>=0&&ix<W&&iy>=0&&iy<H);
    };
    WeightedGraph<ll> graph(H*W);
    REP(y,H){
        REP(x,W){
            auto idx=calc_idx(x,y);
            auto add_edge = [&](ll nx, ll ny){
                auto nex_idx=calc_idx(nx,ny);
                if (check_inside(nx,ny)){
                    auto c = get_map(nx,ny);
                    ll cost=0;
                    if (c=='#') cost=1;
                    graph.at(idx).edges.emplace_back(nex_idx,cost);
                }
            };
			add_edge(x-1,y);
			add_edge(x+1,y);
			add_edge(x,y-1);
			add_edge(x,y+1);
		}
	}
    ll st_idx=-1,ed_idx=-1;
    REP(y,H) REP(x,W) {
        auto c=get_map(x,y);
        if(c=='s') st_idx=calc_idx(x,y);
        if(c=='g') ed_idx=calc_idx(x,y);
    }
    vector<int> prev;
    auto dist = dijkstra(graph,st_idx,prev);
    dump(dist);
    if (dist.at(ed_idx)<=2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}