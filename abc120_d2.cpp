//https://atcoder.jp/contests/abc120/tasks/abc120_d
//D - Decayed Bridges
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
  vector<pair<ll,ll>> abm(M);
  for(auto&& ab:abm){
    cin>>ab.first>>ab.second;
  }
  ll sum=0;
  vector<ll> sums;
  uf_tree ut(N+1);
  for(ll i=M-1;i>=0;--i){
    sums.push_back(sum);
    const auto& ab=abm.at(i);
    if(ut.is_same(ab.first,ab.second)){
      ll n0 = ut.size(ab.first);
      sum -= n0*(n0-1)/2;
    } else{
      ll n0 = ut.size(ab.first);
      sum -= n0*(n0-1)/2;
      ll n1 = ut.size(ab.second);
      sum -= n1*(n1-1)/2;
    }

    ut.unite(ab.first,ab.second);

    ll n3 = ut.size(ab.first);
    sum += n3*(n3-1)/2;
  }
  dump(sums);
  ll ttl=N*(N-1)/2;
  for(auto it=sums.rbegin();it!=sums.rend();++it){
    ll ans=(ttl-*it);
    cout<<ans<<endl;
  }
  return 0;
}