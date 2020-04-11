//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A&lang=ja
//素因数分解
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

template< typename T >
std::vector<std::pair<T,T>> prime_factor_decomp(T n) {
    std::vector<std::pair<T,T>> pe_tbl;
    T m = n;
    for (T i = 2; i * i <= n; i++) {
        if (m % i != 0) continue;
        T c = 0;
        while (m % i == 0) c++, m /= i;
        pe_tbl.emplace_back(i,c);
    }
    if (m > 1) {
        pe_tbl.emplace_back(m,1);
    }
    return pe_tbl;
}

int main() {
  ll n; cin>>n;
  auto ret=prime_factor_decomp(n);
  vector<ll> ans;
  for(const auto& p:ret){
    REP(i,p.second){
      ans.emplace_back(p.first);
    }
  }  
  cout<<n<<":";
  for(const auto& a:ans){
    cout<<" "<<a;
  }
  cout<<endl;

  return 0;
}