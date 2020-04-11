//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1166&lang=jp
//https://onlinejudge.u-aizu.ac.jp/problems/1166
//Problem B: 迷図と命ず
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

bool solve(){
    ll w,h; cin>>w>>h;
    if(w==0&&h==0) return false;
    ll N=w*h;
    auto get_no =[&](ll x, ll y)->ll{
        return x+y*w;
    };
    WeightedGraph<ll> graph(N);
    FOR(i,0,2*h-1){
        if(i%2==0){
            FOR(x,0,w-1){
                ll flag; cin>>flag; //よこ
                if(not flag){
                    auto a = get_no(x,i/2);
                    auto b = get_no(x+1,i/2);
                    graph.at(a).edges.emplace_back(b,1);
                    graph.at(b).edges.emplace_back(a,1);
                }
            }
        }else{
            FOR(x,0,w){
                ll flag; cin>>flag; //たて
                if(not flag){
                    auto a = get_no(x,i/2);
                    auto b = get_no(x,i/2+1);
                    graph.at(a).edges.emplace_back(b,1);
                    graph.at(b).edges.emplace_back(a,1);
                }
            }
        }
    }

    vector<int> prev;
    auto r = dijkstra<ll>(graph,0,prev);
    ll ans = r.at(N-1);
	if(ans >= numeric_limits<ll>::max()) ans=0;
    else ans++;
    cout<<ans<<endl;

    return true;
}

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    while(solve()){
    }    
    return 0;
}