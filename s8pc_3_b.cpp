//https://atcoder.jp/contests/s8pc-3/tasks/s8pc_3_b
//B - 石落としゲーム
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
  using Mat = vector<vector<ll>>;
  vector<vector<ll>> chw(H,vector<ll>(W));
  vector<string> chw_str(H);
  REP(i,H){
    cin>>chw_str[i];
    const auto& s=chw_str[i];
    FOR(x,0,s.size()){
      ll v=s.at(x)-'0';
      chw[i][x]=v;
    }
  }

  auto kesu_line = [&](vector<ll>& ln)->ll{
    ll result=0;
    for(ll x=0;x<W;++x){
      ll sc=ln[x];
      if(sc==0)continue;
      ll num=1;
      while(true){
        ll cx=x+num;
        if(cx>=W)break;
        if(sc==ln[cx]) ++num;
        else {
          break;
        }
      }
      if(num>=K){
        FOR(i,x,x+num){
          result += ln[i];
          ln[i]=0;
        }
      }
    }
    return result;
  };
  auto kesu = [&](Mat& mat)->ll{
    ll result=0;
    FOR(y,0,H){
      result += kesu_line(mat.at(y));
    }
    return result;
  };
  auto otosu_line = [&](Mat& mat, ll ix){
    for(ll y=H-1;y>=1;--y){
      if(mat[y][ix]==0){
        for(ll ty=y-1;ty>=0;--ty){
          if (mat[ty][ix]!=0){
            swap(mat[y][ix],mat[ty][ix]);
            break;
          }
        }
      }
    }
  };
  auto otosu = [&](Mat& mat){
    FOR(x,0,W){
      otosu_line(mat, x);
    }
  };

  //一番した調べればいいだけではないな...
  ll ans=0;
  //ll del_y=H-1;
  FOR(del_y,0,H)
  FOR(del_x,0,W){
    auto wk=chw; //copy
    wk[del_y][del_x]=0;
    otosu_line(wk,del_x);

    ll rate=1;
    ll score=0;
    do{
      ll r = kesu(wk);
      dump(rate,r,wk);
      if(r==0)break;
      score += (r * rate);
      rate *= 2;
      otosu(wk);
    }while(true);
    chmax(ans,score);
  }
  cout<<ans<<endl;

  return 0;
}