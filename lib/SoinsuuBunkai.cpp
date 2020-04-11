//prime factorization
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

//約数を列挙 O(√N)
vector< ll > divisor(ll n) {
  vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

//素因数分解
//n,素因数分解する数
//return first  素数, second いくつ のtable
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
//return first  素数
//return second いくつ
//n=5000だと
//first{2,5} second{3,4} -> 5000=2^3*5^4
template< typename T >
std::pair<std::vector<T>, std::vector<T>> prime_factor_decomp2(T n) {
    std::vector<T> p, e;
    T m = n;
    for (T i = 2; i * i <= n; i++) {
        if (m % i != 0) continue;
        T c = 0;
        while (m % i == 0) c++, m /= i;
        p.push_back(i);
        e.push_back(c);
    }
    if (m > 1) {
        p.push_back(m);
        e.push_back(1);
    }
    return std::make_pair(p, e);
}

int main() {
    int test=5000;
    ll ans = 1;
    auto pe = prime_factor_decomp2(test);
    for(int i=0;i<pe.second.size();++i){
      ans = ans * (pe.second.at(i) + 1); //それぞれを+1して掛けていく
    }
    cout<<ans<<endl;

    auto pe2 = prime_factor_decomp(test);
    for(const auto& p:pe2) {
      cout<<p.first<<":"<<p.second<<endl;
    }

    auto r = divisor(16);
    for(auto v:r){
      cout<<v<<" ";
    }
    cout<<endl;
    return 0;
}