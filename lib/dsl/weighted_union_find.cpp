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
