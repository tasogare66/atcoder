//木の直径,aoj_grl_5_a
template< typename T >
pair< T, int > tree_dfs(const WeightedGraph< T > &g, int idx, int par) {
    pair< T, int > ret(0, idx);
    for(auto &e : g[idx].edges) {
        if(e.to == par) continue;
        auto cost = tree_dfs(g, e.to, idx);
        cost.first += e.cost;
        ret = max(ret, cost);
    } 
    return ret;
}

//st_idx探索開始のidx
template< typename T >
T tree_diameter(const WeightedGraph< T > &g, int st_idx) {
    auto p = tree_dfs(g, st_idx, -1); //st_idxから最遠頂点
    auto q = tree_dfs(g, p.second, -1); //上記の最遠頂点からの最遠頂点
    return (q.first);
}
