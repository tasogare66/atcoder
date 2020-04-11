//https://atcoder.jp/contests/abc159/tasks/abc159_b
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
  std::ifstream in("./test/sample-2.in");
  //std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  string S; cin>>S;
  auto len=S.length();

  bool ans=true;
  //eはふくまない
  auto check_kaibun = [&](ll s, const ll e)->bool{
    for(ll i=s;i<e;++i){
      ll pt=e-i-1;
      if(i>=pt||pt<0) break;
      if (S.at(i)!=S.at(pt)) {
        dump(false);
        return false;
      }
    }
    dump(true);
    return true;
  };

  ans &= check_kaibun(0,S.length());
  ans &= check_kaibun(0,(len-1)/2);
  ans &= check_kaibun(len+3/2-1,len);
  cout<<(ans?"Yes":"No")<<endl;

  return 0;
}