//https://atcoder.jp/contests/abc138/tasks/abc138_d
//D - Ki
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
    ll count=0;
    ll total=0;
    bool flag=false;
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< node< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;
//template graphで書き直し
int main(){
    ll N,Q; cin>>N>>Q;
    WeightedGraph<ll> graph(N+1);    
    REP(i,N-1){
        ll a,b; cin>>a>>b;
        graph.at(a).edges.emplace_back(a,b,1);
        graph.at(b).edges.emplace_back(b,a,1);
    }
    REP(i,Q){
        ll p,q; cin>>p>>q;
        graph.at(p).count+=q;
    }

    function<void(ll,ll)> dfs0 = [&](ll n,ll count){
        auto& node = graph.at(n);
        if(node.flag) return;
        node.flag = true;
        node.total = node.count + count;
        for(auto&& e: node.edges){
            dfs0(e.to, node.total);
        }
    };
    dfs0(1,0);

    FOR(i,1, N+1){
        if (i!=1) cout<<" ";
        cout<<graph.at(i).total;
    }
    cout<<endl;
    return 0;
}

//dfsの訪問済をチェックしてないな.
struct Data{
    ll count=0;
    ll value=0;
    vector<ll> ch;
    vector<ll> pa;
};
vector<Data> nodes;
void dfs(ll no, ll sum){
    auto& cur=nodes[no];
    cur.value = sum+cur.count;
    for(auto& nex:cur.ch){
        dfs(nex, cur.value);
    }
}
int main_() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,Q; cin>>N>>Q;
    nodes.resize(N+1);
    for(ll i=1;i<N;++i){
        ll a,b; cin>>a>>b;
        nodes[a].ch.push_back(b);
        nodes[b].pa.push_back(a);
    }
    REP(i,Q){
        ll p,x; cin>>p>>x;
        nodes[p].count += x;
    }
    //rootから
    dfs(1,0);
    for(ll i=1;i<nodes.size();++i){
        if(i!=1) cout<<" ";
        cout<<nodes[i].value;
    }
    cout<<endl;
    return 0;
}