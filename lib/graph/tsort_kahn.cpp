//トポロジカルソート,kahn
//stackでないで、queue,priority_queue,deque でもよい
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

struct Edge {
    ll st,tr;
    Edge(ll s, ll t)
        : st(s), tr(t)
    {}
};
struct Node{
    vector<Edge> edges;
    ll indeg=0; //入次数
};
using Graph = vector<Node>;

//gの入次数を更新する
vector<ll> tsort_kahn(Graph& g){
    //入次数をカウント,O(E)
    for(auto& n:g){
        for(auto& e:n.edges){
            g.at(e.tr).indeg++;
        }
    }
    //入次数0をstack
    stack<ll> s;
    //priority_queue<ll,vector<ll>,greater<ll>> s; //greaterだと小さい順,昇順に出したい場合これ 
    for(ll i=0;i<g.size();++i){
        if (g.at(i).indeg == 0) {
            s.push(i);
        }
    }
    //入次数0を取っていく
    vector<ll> ret;
    while(s.size() > 0){
        auto u = s.top(); s.pop();
        ret.emplace_back(u);
        for(const auto& e : g.at(u).edges){
            auto v = e.tr;
            g.at(v).indeg--;
            assert(g.at(v).indeg >= 0);
            if (g.at(v).indeg == 0) s.push(v); //入次数,0の頂点を追加
        }
    }
    return ret;
}

int main() {
    //aoj_grl_4_b
    ll vn, en; cin>>vn>>en; //頂点数,辺の数
    Graph graph(vn);
    REP(i,en){
        ll s,t; cin>>s>>t;
        graph.at(s).edges.emplace_back(s,t);
    }

    auto ord = tsort_kahn(graph);
    for(const auto& o:ord){
        cout<<o<<endl;
    }

    return 0;
}