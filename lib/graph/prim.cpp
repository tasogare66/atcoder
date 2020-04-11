template< typename T >
bool operator<(const edge<T> &e, const edge<T> &f) { return e.cost > f.cost; }
template< typename T >
std::pair<T, Edges<T>> prim(const WeightedGraph<T> &g, int r = 0) {
  Edges<T> edges;
  T total = T();
  std::vector<int> vis(g.size());
  std::priority_queue<edge<T>> q;
  q.emplace(-1, r, 0);
  while (q.size()) {
    auto e = q.top();
    q.pop();
    if (vis[e.to]) continue;
    vis[e.to] = true;
    total += e.cost;
    if (e.src != -1) edges.emplace_back(e);
    for (auto &f : g[e.to].edges)
      if (!vis[f.to]) q.emplace(f);
  }
  return std::make_pair(total, edges);
}
