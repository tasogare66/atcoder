//https://atcoder.jp/contests/arc037/tasks/arc037_b
//B - バウムテスト
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif

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
    ll flag=-1;
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
    ll N,M; cin>>N>>M;
    using Node = node<ll>;
    WeightedGraph<ll> graph(N+1);
    REP(i,M){
        ll u,v; cin>>u>>v;
        graph.at(u).edges.emplace_back(v,0);
        graph.at(v).edges.emplace_back(u,0);
    }

    auto all_graph = [&]()->ll{
        FOR(i,1,graph.size()){
            if(graph.at(i).flag==-1) return i;
        }
        return 0; //0はおわり
    };
    function<bool(ll,ll,ll)> dfs = [&](ll no, ll setno, ll from)->bool{
        if (graph.at(no).flag != -1) return false;
        auto& n = graph.at(no);
        n.flag=setno;
        bool ret=true;
        for(const auto& e:n.edges){
            if (from!=e.to){
                ret &= dfs(e.to,setno,no);
            }
        }
        return ret;
    };
    ll no=0;
    ll ans=0;
    while(auto idx=all_graph()){
        dump(idx);
        if (dfs(idx,no++,0)) ++ans;
    }
    cout<<ans<<endl;

    return 0;
}