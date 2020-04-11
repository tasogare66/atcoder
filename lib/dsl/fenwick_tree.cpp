//Binary Indexed Tree (Fenwick Tree)
//https://tubo28.me/compprog/algorithm/fenwick-tree/
//O(logN)
// fenwick_tree<T> t(n)
// サイズ n，型 T の木を作る
// t.sum(l,r)
// [l, r) の和を求める
// t.sum(r) [0, r) の和
// t.add(i,a)
// 0-indexed で i 番目の要素に a を足す
//
// vector<ll> an={1,2,3,4,5};
// fenwick_tree<ll> tmp(an.size());
// FOR(i,0,an.size()){
//     tmp.add(i,an[i]); //add(0,1),add(1,2),add(2,3)...
// }
// FOR(i,0,an.size()+1){
//     dump(i,tmp.sum(i)); //i=0,sum(i)=0, i=1,sum(i)=1, i=2,sum(i)=3,...,i=5,sum(i)=15
// }
template <class T>
struct fenwick_tree {
    int n;
    std::vector<T> x;
    fenwick_tree(int n_ = 0) : n(n_), x(n + 1, 0) {}
    int size() const { return n; }
    T sum(int r) const {
        T S = 0;
        for (r = r - 1; r >= 0; r = (r & (r + 1)) - 1) S += x[r];
        return S;
    }
    T sum(int l, int r) const { return sum(r) - sum(l); }
    void add(int k, const T &a) {
        for (; k < n; k |= k + 1) x[k] += a;
    }
    void set(int k, const T &a) { add(k, a - sum(k, k + 1)); }
};

template <class T>
struct fenwick_tree_range {
    fenwick_tree<T> a, b;
    fenwick_tree_range(int n = 0) : a(n), b(n) {}
    int size() const { return a.size(); }
    T sum(int r) const { return a.sum(r) + b.sum(r) * r; }
    T sum(int l, int r) const { return sum(r) - sum(l); }
    void add(int r, const T &x) {
        a.add(r, x * r);
        b.add(r, -x);
    }
    void add(int l, int r, const T &x) {
        add(l, -x);
        add(r, x);
    }
};