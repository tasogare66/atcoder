//https://atcoder.jp/contests/abc161/tasks/abc161_d
//D - Lunlun Number
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
  // auto test_func = [&](){
  //   ll keta_max=5;
  //   vector<vector<ll>> tbl(keta_max,vector<ll>(10));
  //   FOR(d,1,10){
  //     tbl[0][d]=1;
  //   }
  //   FOR(k,1,keta_max){
  //     FOR(d,0,10){
  //       tbl[k][d] = tbl[k-1][d];
  //       if(d-1>0) tbl[k][d] += tbl[k-1][d-1];
  //       if(d+1<10) tbl[k][d] += tbl[k-1][d+1];
  //     }
  //   }
  //   dump(tbl);
  // };
  // test_func();
#if LOCAL&01
  std::ifstream in("./test/sample-1.in");
  //std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll K; cin>>K;
  //bfs
  ll cnt=0;
  priority_queue<ll, vector<ll>, greater<ll> > que;

  auto check_cnt = [&](ll v){
    ++cnt;
    if(K<=cnt){
      cout<<v<<endl;
      exit(0);
    }
  };

  FOR(i,1,10){
    que.push(i);
    check_cnt(i);
  }
  while(true){
    auto v = que.top();
    que.pop();
    ll d0 = v%10;
    auto check_push = [&](ll d){
      if (d>=0&&d<=9) {
        ll tmp=v*10+d;
        que.push(tmp);
        check_cnt(tmp);
      }
    };
    check_push(d0-1);
    check_push(d0);
    check_push(d0+1);
  }
  return 0;
}