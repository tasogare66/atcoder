//https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d
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
  ll N; cin>>N;
  string S; cin>>S;

  auto check=[&](vector<ll> vec){
    ll p=0;
    FOR(i,0,S.size()){
      ll v= S.at(i)-'0';
      if(vec.at(p)==v){
        ++p;
        if(p==vec.size())return true;
      }
    }
    return false;
  };
  ll ans=0;
  FOR(i,0,10){
    FOR(j,0,10) FOR(k,0,10){
      if (check({i,j,k})){
        ++ans;
      }
    }
  }
  cout<<ans<<endl;  
  return 0;
}