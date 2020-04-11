//https://atcoder.jp/contests/abc159/tasks/abc159_e
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
  std::ifstream in("./test/sample-3.in");
  //std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll H,W,K; cin>>H>>W>>K;
  vector<string> shw(H);
  for(auto&& sw:shw){
    cin>>sw;
  }

  vector<vector<ll>> sums(H+1, vector<ll>(W+1));
  FOR(y,1,H+1){
    FOR(x,1,W+1){
      sums[y][x]=sums[y][x-1];
      auto c=shw.at(y-1).at(x-1);
      if(c=='1'){
        sums[y][x]+=1;
      }
    }
  }
  FOR(x,1,W+1){
    FOR(y,1,H+1){
      sums[y][x]+=sums[y-1][x];
    }
  }
  auto getnum = [&](ll x0, ll y0, ll x1, ll y1){
    return sums[y1][x1] - sums[y0-1][x1] - sums[y1][x0-1] + sums[y0-1][x0-1];
  };

  ll bitmax=2<<(H-1-1);
  vector<vector<ll>> ytbl(bitmax);
  FOR(m,0,bitmax){
    ytbl.at(m).push_back(0);
    FOR(j,0,H){
      if(m&(1<<j)){
        ytbl.at(m).push_back(j+1);
      }
    }
    ytbl.at(m).push_back(H);
  }

  ll ans=INT32_MAX;
  FOR(m,0,bitmax){
    const auto& tbl=ytbl[m];
    ll lines =tbl.size()-2;

    ll prev=1;
    FOR(j,1,W+1){
      FOR(k,0,tbl.size()-1){
        auto sty=tbl[k]+1;
        auto edy=tbl[k+1];
        //こえたら線をひく
        ll num = getnum(prev,sty,j,edy);
        if (num>K){
          if(prev==j){
            lines=INT32_MAX;
          }else{
            dump(prev,sty,j,edy,num);
            prev=j;
            ++lines;
          }
          break;
        }
      }
    }
    dump(m, lines);
    chmin(ans,lines);
  }
  cout<<ans<<endl;

  return 0;
}