//https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_d
//D - ぬいぐるみの整理 (Plush Toys)
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
  std::ifstream in("./test/sample-1.in");
  //std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll N,M; cin>>N>>M;
  vector<ll> tn(N);
  for(auto&& t:tn){
    cin>>t;
    --t; //0-indexed
  }
  vector<vector<ll>> sums(M,vector<ll>(N+1));
  vector<ll> ttl(M);
  FOR(i,0,N){
    auto cur_type=tn.at(i);
    ++ttl.at(cur_type);
    FOR(t,0,M){
      sums[t][i+1]=sums[t][i]+(t==cur_type);
    }
  }
  dump(sums);
  dump(ttl);

  auto get_pos = [&](ll m){
    ll ret=0;
    FOR(t,0,M){
      if(m&(1LL<<t))ret+=ttl.at(t);
    }
    return ret;
  };
  dump(get_pos(0))
  dump(get_pos(2));
  dump(get_pos(4));
  dump(get_pos(2+4));

  ll bit_max=(1LL<<(M));
  vector<ll> dp(bit_max,LINF);
  dp[0]=0;
  FOR(m,0,bit_max){
    FOR(t,0,M){ //次にいれるmask
      ll next_m=m|(1<<t);
      if(next_m==m) continue;
      auto p0 = get_pos(m);
      auto p1 = get_pos(next_m);
      ll kukan_num=sums[t][p1]-sums[t][p0]; //区間にある数
      ll add_num=ttl[t]-kukan_num; //区間にないやつは加える
      dump(add_num,t,p0,p1);
      chmin(dp[next_m],dp[m]+add_num);
    }
  }
  dump(dp);
  cout<<dp[bit_max-1]<<endl;

  return 0;
}