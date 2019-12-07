//https://atcoder.jp/contests/soundhound2018-summer-qual/tasks/soundhound2018_summer_qual_d
//D - Saving Snuuk
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
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
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll n,m,s,t; cin>>n>>m>>s>>t;
    WeightedGraph<ll> graph_a(n+1), graph_b(n+1);
    REP(i,m){
        ll u,v,a,b; cin>>u>>v>>a>>b;
        graph_a.at(u).edges.emplace_back(v,a);
        graph_a.at(v).edges.emplace_back(u,a);
        graph_b.at(u).edges.emplace_back(v,b);
        graph_b.at(v).edges.emplace_back(u,b);
    }
    vector<int> tmp;
    constexpr ll INF=numeric_limits<ll>::max();
    auto res_a = dijkstra(graph_a,s,tmp);
    auto res_b = dijkstra(graph_b,t,tmp);
    vector<ll> a_b(res_a.size());
    REP(i,a_b.size()){
        auto ra = res_a.at(i);
        auto rb = res_b.at(i);
        if (ra>=INF||rb>=INF) {
            a_b.at(i)=-1;//INF;
        }else{
            a_b.at(i)=1e15-(ra+rb);
        }
    }
    vector<ll> ans(a_b.size());
    ll max_a=0;
    for(ll i=a_b.size()-1;i>=0;--i){
        auto v=a_b.at(i);
        max_a=max(max_a,v);
        ans.at(i)=max_a;
    }
    FOR(i,1,ans.size()){
        cout<<ans.at(i)<<endl;
    }
#if 0
    REP(i,n){
        ll ans=INF;
        FOR(j,i+1,n+1){
            //if(i>=j)continue;
            auto ra = res_a.at(j);
            auto rb = res_b.at(j);
            if (ra>=INF||rb>=INF) continue;
            ans=min(ra+rb,ans);
        }
        ans=1e15-ans;
        cout<<ans<<endl;
    }
#endif
    return 0;
}