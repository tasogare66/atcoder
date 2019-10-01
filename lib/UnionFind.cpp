//union find
#include <bits/stdc++.h>

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

//https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll n, q; cin>>n>>q;
    uf_tree uft(n);
    REP(i,q){
        ll com,x,y; cin>>com>>x>>y;
        if (com==0){ //連結
            uft.unite(x,y);
        }else{
            cout<<uft.is_same(x,y)<<endl;
        }
    }
    return 0;
}