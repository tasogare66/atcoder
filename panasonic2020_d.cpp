//https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_d
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

int main() {
#if LOCAL&0
  std::ifstream in("./test/sample-2.in");
  //std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll N; cin>>N;

  string S;
  REP(i,N){
    S.push_back('a');
  }

  auto dfs = [N](auto&& self, const ll n, string& s, ll t){
    if(n>=N) {
      cout<<s<<endl;
      return;
    }
    //dump(t);
    //FOR(i,0,n+1){
    FOR(i,0,t+1){
      s.at(n)=(char)('a'+i);
      self(self, n+1, s, max(t,i+1));
    }
  };

  dfs(dfs, 0, S, 0);

  return 0;
}