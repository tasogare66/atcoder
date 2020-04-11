//https://atcoder.jp/contests/abc075/tasks/abc075_c?lang=ja
//C - Bridge
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
const ll LINF = 0x1fffffffffffffff;
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
  std::ifstream in("./test/sample-1.in");
  //std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll N,M; cin>>N>>M;
  vector<pair<int,int>> cnt(M);
  for(auto&& p:cnt){
    cin>>p.first>>p.second;
  }
  ll ans=0;
  REP(i,M){
    uf_tree uft(N+1);
    REP(j,M){
      if(i==j)continue;
      uft.unite(cnt[j].first, cnt[j].second);
    }
    if(uft.size()-1>1) ++ans;
  }
  cout<<ans<<endl;
  return 0;
}