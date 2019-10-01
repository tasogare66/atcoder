//https://atcoder.jp/contests/abc097/tasks/arc097_b
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
    ll N,M; cin>>N>>M;
    vector<ll> pn(N+1);
    FOR(i,1,N+1){
        cin>>pn.at(i);
    }
    uf_tree ut(N+1);
    REP(m,M){
        int x,y; cin>>x>>y;
        ut.unite(x,y);
    }

    ll ans=0;
    FOR(i,1,N+1){
        if (i==pn.at(i)){
            ++ans;
        }else{
            if (ut.is_same(i,pn.at(i))) ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}