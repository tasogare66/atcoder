//https://atcoder.jp/contests/aising2019/tasks/aising2019_c
//C - Alternating Path
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
    std::ifstream in("./test/sample-3.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll H,W; cin>>H>>W;
    vector<string> sh(H);
    for(auto&& s:sh){
        cin>>s;
    }
    ll n=H*W;

    uf_tree uft(n);
    auto idx = [&](ll x,ll y){
        return y*W+x;
    };
    auto getch = [&](ll x,ll y){
        return sh.at(y).at(x);
    };
    auto check_same = [&](ll x0,ll y0,ll x1,ll y1){
         return getch(x0,y0)==getch(x1,y1);
    };
    FOR(y,0,H){
        FOR(x,0,W){
            if (x+1<W && !check_same(x,y,x+1,y)) {
                uft.unite(idx(x,y), idx(x+1,y));
            }
            if (y+1<H && !check_same(x,y,x,y+1)) {
                uft.unite(idx(x,y),idx(x,y+1));
            }
        }
    }
    ll ans=0;
    ll b[n]={};
    ll w[n]={};
    FOR(y,0,H){
        FOR(x,0,W){
            auto p = uft.find(idx(x,y));
            if(getch(x,y)=='#'){
                ++b[p];
            }else{
                ++w[p];
            }
        }
    }
    REP(i,n){
        ans += b[i]*w[i];
    }
    cout<<ans<<endl;
    return 0;
}