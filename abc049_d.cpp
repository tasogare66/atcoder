//https://atcoder.jp/contests/abc049/tasks/arc065_b
//D - 連結 / Connectivity
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
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,K,L; cin>>N>>K>>L;
    uf_tree ut_k(N+1), ut_l(N+1);
    REP(i,K){
        int p,q; cin>>p>>q;
        ut_k.unite(p,q);
    }
    REP(i,L){
        int r,s; cin>>r>>s;
        ut_l.unite(r,s);
    }
    map<pair<int,int>,int> tbl; //rootが一致している
    FOR(i,1,N+1){
        int a=ut_k.find(i);
        int b=ut_l.find(i);
        tbl[{a,b}]++;
    }
    FOR(i,1,N+1){
        auto a=ut_k.find(i);
        auto b=ut_l.find(i);
        cout<<tbl[{a,b}]<<endl;
    }
    // FOR(i,1,N+1){ //全探索?
    //     ll ans=0;
    //     FOR(j,1,N+1){
    //         if (ut_k.is_same(i,j) && ut_l.is_same(i,j)){
    //             ++ans;
    //         }
    //     }
    //     cout<<ans<<endl;
    // }

    return 0;
}