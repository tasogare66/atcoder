//https://atcoder.jp/contests/cf16-final/tasks/codefestival_2016_final_c
//C - Interpretation
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
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,M; cin>>N>>M;    
    unordered_map<ll,vector<ll>> lang_n_map;
    FOR(i,1,N+1){
        ll k; cin>>k;
        REP(j,k){
            ll L; cin>>L;
            lang_n_map[L].push_back(i);
        }
    }

    uf_tree uft(N+1);
    for(const auto& lnm :lang_n_map){
        auto fn = lnm.second.front();
        FOR(i,1,lnm.second.size()){
            uft.unite(fn, lnm.second.at(i));
        }
    }
    bool ans=(uft.size(1) == N);
    cout<<(ans?"YES":"NO")<<endl;
    return 0;
}