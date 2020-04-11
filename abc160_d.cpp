//https://atcoder.jp/contests/abc160/tasks/abc160_d
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
  ll N,X,Y; cin>>N>>X>>Y;
  vector<ll> ans(N);
  //となりを考慮  
  FOR(i,1,N+1){
    unordered_map<ll,ll> ch;
    FOR(d,1,N){
      auto&& a=ans.at(d);

      auto check_inc = [&](ll tv){
        dump(i,d,tv);
        if(tv<=i)return;
        if(tv>=1&&tv<=N){
          if(ch.count(tv)==0){
            dump(i,d,tv,"add");
            ch[tv]=1;
            ++a;
          }
        }
      };

      ll tmp0=i+d;
      check_inc(tmp0);

      ll ix=abs(i-X);
      ll nokori=d-ix-1;
      if(nokori>=0){
        ll tmpa = Y+nokori;
        check_inc(tmpa);
        ll tmpb = Y-nokori;
        check_inc(tmpb);
      }
      // ll tmp1=i+d-X;
      // if(tmp1>0) {
      //   ll tmpa=Y+tmp1-1;
      //   check_inc(tmpa);

      //   ll tmpb=Y-(tmp1-1);
      //   check_inc(tmpb);
      // }
    }
    dump(ans);
  }
  FOR(i,1,ans.size()){
    cout<<ans.at(i)<<endl;
  }
  return 0;
}