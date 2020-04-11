//https://atcoder.jp/contests/abc157/tasks/abc157_d
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

struct uf_tree {
    std::vector<int> parent;
    int __size;
    uf_tree(int size_) : parent(size_, -1), __size(size_) {}
    void unite(int x, int y) {
        if ((x = find(x)) != (y = find(y))) {
            if (parent[y] < parent[x]) std::swap(x, y);
            parent[x] += parent[y];
            parent[y] = x;
            __size--;
        }
    }
    bool is_same(int x, int y) { return find(x) == find(y); }
    int find(int x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }
    int size(int x) { return -parent[find(x)]; }
    int size() { return __size; }
};

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-3.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N, M, K; cin>>N>>M>>K;
    vector<set<ll>> frd(N+1);
    vector<set<ll>> blk(N+1);
    uf_tree uft(N+1);
    REP(i,M){
        ll a,b; cin>>a>>b;
        frd.at(a).insert(b);
        frd.at(b).insert(a);
        uft.unite(a,b);
    }
    REP(i,K){
        ll a,b; cin>>a>>b;
        blk.at(a).insert(b);
        blk.at(b).insert(a);
    }

    FOR(i,1,frd.size()){
        ll ans=uft.size(i)-frd.at(i).size()-1;
        for(auto& b: blk.at(i)){
            if(uft.is_same(i,b))--ans;
        }
        if(i!=1)cout<<" ";
        cout<<ans;
    }
    cout<<endl;

    return 0;
}