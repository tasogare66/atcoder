//https://atcoder.jp/contests/abc146/tasks/abc146_d
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
    T no;
    ll col=0;
	edge(int _to, T _cost) : src(-1), to(_to), cost(_cost) {}
	edge(int _src, int _to, T _cost, T _no) : src(_src), to(_to), cost(_cost), no(_no) {}
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

vector<ll> col; //edgeのいろ1-N-1
//木の直径,aoj_grl_5_a
template< typename T >
pair< T, int > tree_dfs(const WeightedGraph< T > &g, int idx, int par) {
    pair< T, int > ret(0, idx);
    map<ll,ll> tmp; //---
    for(auto &e : g[idx].edges) {
        ll id=e.no; //edgeの番号
        if(col.at(id)!=0) tmp[col.at(id)]=1;
    }
    ll cn=1;
    auto get_col = [&](){
        while(tmp.count(cn)){
            ++cn;
        }
        return cn++;
    };
    for(auto &e : g[idx].edges) {
        ll id=e.no; //edgeの番号
        if(col.at(id)==0) {
            col.at(id)=get_col();
        }else{
        }
    } //---
    for(auto &e : g[idx].edges) {
        if(e.to == par) continue;
        auto cost = tree_dfs(g, e.to, idx);
        cost.first += e.cost;
        ret = max(ret, cost);

        ll id=e.no; //edgeの番号
        auto c=col.at(id);
    } 
#if 0
    map<ll,ll> tmp;
    for(auto &e : g[idx].edges) {
        ll id=e.no; //edgeの番号
        if(col.at(id)!=0) tmp[col.at(id)]=1;
    }
    ll cn=1;
    auto get_col = [&](){
        while(tmp.count(cn)){
            ++cn;
        }
        return cn;
    };
    for(auto &e : g[idx].edges) {
        ll id=e.no; //edgeの番号
        if(col.at(id)==0) {
            col.at(id)=get_col();
        }else{

        }
    }
#endif
    return ret;
}

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    WeightedGraph<ll> graph(N+1);
    col.resize(N,0);
    FOR(i,1,N){
        ll a,b; cin>>a>>b;
        graph.at(a).edges.emplace_back(a,b,1,i);
        graph.at(b).edges.emplace_back(b,a,1,i);
    }
    ll color_num=0;
    FOR(i,1,graph.size()){
        if (chmax<ll>(color_num,graph.at(i).edges.size())){
        }
    }

    tree_dfs(graph, 1,-1);
    dump(col);

    cout<<color_num<<endl;
    FOR(i,1,col.size()){
        cout<<col.at(i)<<endl;
    }

    return 0;
}