//https://atcoder.jp/contests/abc087/tasks/arc090_b
//D - People on a Line
//重み付きunionfind (http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B&lang=jp)
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//重み付きUnion Find木
template<class T>
struct wuf_tree {
    std::vector<int> parent;
    std::vector<T> diff_weight;
    int __size;
    wuf_tree(int size_, T sum_unity=T()) : parent(size_, -1), diff_weight(size_,sum_unity), __size(size_) {}
    void unite(int x, int y, T w) {
        w += weight(x);
        w -= weight(y);
        if ((x = find(x)) != (y = find(y))) {
            if (parent[y] < parent[x]) { std::swap(x, y); w=-w; }
            parent[x] += parent[y];
            parent[y] = x;
            diff_weight[y] = w;
            __size--;
        }
    }
    bool is_same(int x, int y) { return find(x) == find(y); }
    int find(int x) {
        if (parent[x]<0) return x;
        int r = find(parent[x]);
        diff_weight[x] += diff_weight[parent[x]];
        return parent[x] = r;
    }
    int size(int x) { return -parent[find(x)]; }
    int size() const { return __size; }
    T weight(int x) { find(x); return diff_weight[x]; }
    T diff(int x, int y) { return weight(y) - weight(x); }
};

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,M; cin>>N>>M;    
    wuf_tree<ll> wuft(N+1);
    REP(i,M){
        ll l,r,d; cin>>l>>r>>d;
        if (wuft.is_same(l,r)){
            if (wuft.diff(l,r) != d) {
                cout<<"No"<<endl;
                return 0;
            }
        }
        wuft.unite(l,r,d);
    }
    cout<<"Yes"<<endl;
    return 0;
}