//https://atcoder.jp/contests/abc120/tasks/abc120_d
//D - Decayed Bridges
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
    vector<pair<int,int>> abm(M);
    for(auto&& ab:abm){
        cin>>ab.first>>ab.second;
    }

    uf_tree ut(N+1);
    //ll a=0;
    vector<ll> ans;
    for(ll i=M-1;i>=0;--i){ //逆から
        //ll a=0;
        // FOR(sima,1,N+1){
        //     dump(sima,ut.size(sima));
        //     a+=ut.size(sima)-1;
        // }
        // ans.push_back(a/2);

        const auto& dec=abm.at(i);

        ll pa=ut.size(dec.first);
        ll pb=ut.size(dec.second);

        ut.unite(dec.first,dec.second);
        //dump(ut.size(dec.first),ut.size());
        ll aa=ut.size(dec.first);
        ll ab=ut.size(dec.second);
        dump(pa,pb,aa,ab);
        ll a = (aa-pa)*(ab-pb);
        ans.push_back(a);
    }

    //ll nc2=N*(N-1)/2;
    ll a=0;
    reverse(ans.begin(),ans.end());
    for(const auto& o:ans){
        //cout<<nc2-o<<endl;
        a+=o;
        cout<<a<<endl;
    }
    return 0;
}
