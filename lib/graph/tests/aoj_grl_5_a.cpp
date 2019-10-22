//https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

#include "../template_graph.cpp"
#include "../tree_diameter.cpp"

int main() {
    ll n; cin>>n;
    WeightedGraph<ll> graph(n);
    REP(i,n-1){
        ll s,t,w; cin>>s>>t>>w;
        graph.at(s).edges.emplace_back(s,t,w);
        graph.at(t).edges.emplace_back(t,s,w);
    }
    auto dm = tree_diameter(graph,0);
    cout<<dm<<endl;
    return 0;
}