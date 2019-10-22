//単一始点最短路 (Bellman Ford)
//ある 2 頂点間の距離を,その間の辺を使って短く更新できる限り更新するということを繰り返します．
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#include "template_graph.cpp"

//s start node
//return 各nodeへの最短の距離, numeric_limits< T >::max() と等しい場合INF(=到達できない) , emptyの場合負の閉路
template< typename T >
vector< T > bellman_ford(const Edges< T > &edges, int V, int s) {
    const auto INF = numeric_limits< T >::max();
    vector< T > dist(V, INF);
    dist[s] = 0;
    //辺の緩和を反復
    for(int i = 0; i < V - 1; i++) {
        for(auto &e : edges) {
            if(dist[e.src] == INF) continue;
            dist[e.to] = min(dist[e.to], dist[e.src] + e.cost);
        }
    }
    //負の重みの閉路がないかチェック
    for(auto &e : edges) {
        if(dist[e.src] == INF) continue;
        if(dist[e.src] + e.cost < dist[e.to]) return vector< T >();
    }
    //MEMO:一か所でも負の経路があると,空を返す
    //負の閉路の影響があるかは,以下 negativeがtrueの箇所は影響あり(=無限にcost下げられる) ex.abc061_d
    // negative.assign(V,false);
    // for (ll i=0;i<V;i++){
    //     for(auto &e : edges) {
    //         if(dist[e.src] == INF) continue;
    //         if(dist[e.src] + e.cost < dist[e.to]) negative.at(e.to)=true;
    //         if(negative.at(e.src)) negative.at(e.to)=true;
    //     }
    // }
    return dist;
}

int main() {
    //aoj_grl_1_b
	//https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    ll V,E; cin>>V>>E;
    ll r; cin>>r;
    Edges<ll> edges;
    REP(e,E){
        int s,t; cin>>s>>t;
		    ll d; cin>>d;
        edges.emplace_back(s,t,d);
    }

    auto result = bellman_ford(edges, V, r);
    if (result.empty()) cout<<"NEGATIVE CYCLE"<<endl;
    else {
        for(const auto& d:result){
            if (d==numeric_limits<ll>::max()) cout<<"INF"<<endl;
            else cout<<d<<endl;;
        }
    }
    return 0;
}
