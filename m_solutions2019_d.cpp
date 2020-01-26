//https://atcoder.jp/contests/m-solutions2019/tasks/m_solutions2019_d
//D - Maximum Sum of Minimum
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
    ll score=0;
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
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    WeightedGraph<ll> graph(N+1);
    FOR(i,0,N-1){
        ll a,b; cin>>a>>b;
        graph.at(a).edges.emplace_back(a,b,0);
        graph.at(b).edges.emplace_back(b,a,0);
    }
    vector<ll> cn(N); //昇順
    FOR(i,0,N){
        cin>>cn.at(i);
    }
    sort(cn.begin(), cn.end());

    ll max_edges_node, max_edges_num=0;
    FOR(i,1,N+1){
        if (chmax<ll>(max_edges_num,graph.at(i).edges.size())){
            max_edges_node=i;
        }
    }

    //nodeに点を入れる
// function 幅優先探索(v)
//     Q ← 空のキュー
//     v に訪問済みの印を付ける
//     v を Q に追加
//     while Q が空ではない do
//         v ← Q から取り出す
//         v を処理する
//         for each v に接続している頂点 i do
//             if i が未訪問 then
//                 i に訪問済みの印を付ける
//                 i を Q に追加
    auto tree_bfs = [&](auto& g, int s){
	    using Pi = pair<ll, int>; //dist,node id
	    priority_queue<Pi, vector<Pi>, less<Pi>> que;
	    vector<bool> visit(g.size(), false);
        visit[s]=true;
        que.emplace(g[s].edges.size(), s);
        while(!que.empty()){
		    ll tmp;
		    int idx; //node id
		    tie(tmp, idx) = que.top();
		    que.pop();
            //vを処理する
            dump(idx);
            g.at(idx).score = cn.back();
            cn.pop_back();

			for(auto &e : g[idx].edges) {
                if(visit[e.to]) continue;
				visit[e.to] = true;
				que.emplace(g[e.to].edges.size(), e.to);
			}
		}
    };

    tree_bfs(graph,max_edges_node);
    ll ans=0;
    FOR(i,1,N+1){
        for(auto& e:graph[i].edges){
            ans += min(graph[e.to].score, graph[e.src].score);
        }
    }
    assert(ans%2==0);
    cout<<ans/2<<endl;
    FOR(i,1,N+1){
        cout<<graph[i].score<<endl;
    }
    return 0;
}