//https://atcoder.jp/contests/abc122/tasks/abc122_b
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
  string S; cin>>S;
  vector<char> ch={'A','C','G','T'};
  auto check=[&](char ic){
    for(const auto&c:ch){
      if(ic==c)return true;
    }return false;
  };
  ll ans=0;
  ll cnt=0;
  for(auto&c :S){
    if(check(c)){
      ++cnt;
      chmax(ans,cnt);
    }else{
      cnt=0;
    }
  }
  cout<<ans<<endl;
  return 0;
}