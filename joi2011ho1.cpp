//https://atcoder.jp/contests/joi2011ho/tasks/joi2011ho1
//A - 惑星探査 (Planetary Exploration)
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
#if LOCAL&01
  //std::ifstream in("./test/sample-1.in");
  std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll M,N; cin>>M>>N;
  ll K; cin>>K;
  vector<string> map(M);
  for(auto&& s:map)cin>>s;

  unordered_map<char,int> cno={
    {'J',0},{'O',1},{'I',2}
  };

  vector<vector<vector<ll>>> sums(3, vector<vector<ll>>(M+1, vector<ll>(N+1)));
  FOR(y,1,M+1){
    FOR(x,1,N+1){
      FOR(t,0,3){
        sums[t][y][x]=sums[t][y][x-1];
      }
      auto c=map.at(y-1).at(x-1);
      auto type=cno[c];
      sums[type][y][x] = sums[type][y][x-1]+1;
    }
  }

  FOR(x,1,N+1){
    FOR(y,1,M+1){
      FOR(t,0,3){
        sums[t][y][x]+=sums[t][y-1][x];
      }
    }
  }

  REP(q,K){
    ll a,b,c,d; cin>>a>>b>>c>>d;
    REP(t,3){
      ll ans=sums[t][c][d] - sums[t][a-1][d] - sums[t][c][b-1] + sums[t][a-1][b-1];
      if(t!=0)cout<<" ";
      cout<<ans;
    }
    cout<<endl;
  }


  return 0;
}