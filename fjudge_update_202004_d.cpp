//https://atcoder.jp/contests/judge-update-202004/tasks/judge_update_202004_d
//D - Calculating GCD
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
  ll N,Q; cin>>N>>Q;
  vector<ll> an(N);
  for(auto&a:an) cin>>a;
  vector<ll> sq(Q);
  for(auto&s:sq) cin>>s;

  ll gcdv=an.at(0);
  vector<ll> gcds(N);
  gcds.at(0)=gcdv;
  FOR(i,1,N){
    gcdv = std::gcd(an.at(i),gcdv);
    gcds.at(i)=gcdv;
  }
  dump(gcds);

  FOR(i,0,Q){
    ll v = std::gcd(gcdv,sq.at(i));
    if(v==1){
      //二分探索
      auto check = [&](ll idx){
        return (1==std::gcd(gcds.at(idx), sq.at(i)));
      };
      ll ok=N-1,ng=-1;
      while(ok-ng>1){
        ll mid = (ok+ng)/2;
        if (check(mid)) {
          ok=mid;
        }else{
          ng=mid;
        }
        dump(mid,ng,ok);
      }
      dump(ok,gcds[ok]);
      cout<<ok+1<<endl;

    }else cout<<v<<endl;
  }

  return 0;
}