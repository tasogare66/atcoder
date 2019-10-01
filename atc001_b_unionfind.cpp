//https://atc001.contest.atcoder.jp/tasks/unionfind_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

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
    ll N, Q; cin>>N>>Q;
    uf_tree uft(N+1);
    REP(q,Q){
        ll p,a,b;
        cin>>p>>a>>b;
        if (p==0){//連結
            uft.unite(a,b);
        }else{
            cout<<(uft.is_same(a,b)?"Yes":"No")<<endl;
        }
    }

    return 0;
}