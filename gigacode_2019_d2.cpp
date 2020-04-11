//https://atcoder.jp/contests/gigacode-2019/tasks/gigacode_2019_d
//D - 家の建設
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
  ll H,W,K,V; cin>>H>>W>>K>>V;
  vector<vector<ll>> ahw(H+1,vector<ll>(W+1));
  FOR(y,1,H+1){
    FOR(x,1,W+1){
      ll a; cin>>a;
      ahw[y][x]=ahw[y][x-1]+a;
    }
  }
  FOR(x,1,W+1){
    FOR(y,1,H+1){
      ahw[y][x]+=ahw[y-1][x];
    }
  }

  auto check_func = [&](ll x0,ll x1, ll y0, ll y1)->ll{
    ll result=0;
    --x0; --y0;
    ll val = ahw[y1][x1] - ahw[y1][x0] - ahw[y0][x1] + ahw[y0][x0];
    ll s=x1*y1 - y1*x0 -y0*x1 + y0*x0;
    if(val + s*K<=V){
      result=s;
    }
    return result;
  };

  ll ans=0;
  FOR(sx,1,W+1) FOR(ex,sx,W+1){
    FOR(sy,1,H+1) FOR(ey,sy,H+1){
      chmax(ans,check_func(sx,ex,sy,ey));
    }
  }

  cout<<ans<<endl;

  return 0;
}