//https://atcoder.jp/contests/s8pc-5/tasks/s8pc_5_b
//B - Emblem
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
  ll N,M; cin>>N>>M;
  struct xyr{
    double x,y,r=-1;
  };
  vector<xyr> xyrn(N);
  vector<xyr> xym(M);
  double ans=FLT_MAX;
  for(auto&& d:xyrn){
    cin>>d.x>>d.y>>d.r;
    chmin(ans,d.r);
  }
  for(auto&& d:xym){
    cin>>d.x>>d.y;
  }
  //連結
  xyrn.insert(xyrn.end(), xym.begin(), xym.end());
  FOR(i, 0, xyrn.size()){
    FOR(j, 0, xyrn.size()){
      if(i==j)continue;
      const auto& a=xyrn.at(i);
      const auto& b=xyrn.at(j);
      if(a.r>0&&b.r>0) continue;
      double vx=a.x-b.x;
      double vy=a.y-b.y;
      double len=sqrt(vx*vx+vy*vy);
      if(a.r>0) {
        chmin(ans, len-a.r);
      }else if(b.r>0){
        chmin(ans, len-b.r);
      }else{
        chmin(ans,len/2.0);
      }
    }
  }
  cout<<fixed<<std::setprecision(10)<<ans<<endl;

  return 0;
}