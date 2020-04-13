//https://atcoder.jp/contests/abc162/tasks/abc162_e
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

template<uint32_t M = 1000000007>
struct modint{
    using u64 = std::uint_fast64_t;
    u64 val;
    modint(): val(0){}
    template<typename T>
    modint(T t){t %= (T)M; if(t < 0) t += (T)M; val = t;}

    modint pow(ll k) const {
        modint res(1), x(val);
        while(k){
            if(k&1) res *= x;
            x *= x;
            k >>= 1;
        }
        return res;
    }
    static modint nCr(ll n, ll r){
        modint a(1),b(1);
        for(ll i=0;i<r;++i){
            a *= (n-i);
            b *= (i+1);
        }
        return a/b;
    }
    template<typename T>
    modint& operator=(T t){t %= (T)M; if(t < 0) t += (T)M; val = t; return *this;}
    modint inv() const {return pow(M-2);}
    modint& operator+=(modint a){val += a.val; if(val >= M) val -= M; return *this;}
    modint& operator-=(modint a){if(val < a.val) val += M-a.val; else val -= a.val; return *this;}
    modint& operator*=(modint a){val = (u64)val*a.val%M; return *this;}
    modint& operator/=(modint a){return (*this) *= a.inv();}
    modint operator+(modint a) const {return modint(val) +=a;}
    modint operator-(modint a) const {return modint(val) -=a;}
    modint operator*(modint a) const {return modint(val) *=a;}
    modint operator/(modint a) const {return modint(val) /=a;}
    modint operator-(){return modint(M-val);}
    bool operator==(const modint a) const {return val == a.val;}
    bool operator!=(const modint a) const {return val != a.val;}
    bool operator<(const modint a) const {return val < a.val;}
    constexpr u64 &value() noexcept { return val; }
    constexpr const u64 &value() const noexcept { return val; }
    friend ostream& operator<<(ostream& os, const modint& dt){
        os<<dt.val;
        return os;
    }
};
constexpr ll MOD=1e9+7;
using mint = modint<MOD>;

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
#if LOCAL&01
  std::ifstream in("./test/sample-1.in");
  //std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll N,K; cin>>N>>K;

  //auto pd = prime_factor_decomp(K);

  mint ans=K;
  ans=ans.pow(N);

  FOR(i,2,K+1){
    if(K%i==0){
      ll tmp=K/i;
      auto pd = prime_factor_decomp(tmp);
      ll num=1;
      if (pd.size()>0){
        for(const auto&p:pd){
          num *= (p.second+1);
        }
      }
      dump(i,num);
      if(num==1){
        ans -= 1;
        ans += mint(i);
      }else{
        mint v=num;
        mint ruij = v.pow(N)-1;
        ans -= ruij;
        ans += mint(ruij*i);
      }
    }else{
      ans -= 1;
      ans += i;
    }
  }
  cout<<ans<<endl;
#if 0
  mint ans=0;
  FOR(i,1,K+1){
    if(K%i==0){
      ll tmp=K/i;
      auto pd = prime_factor_decomp(tmp);
       ll num=1;
      if (pd.size()>0){
        for(const auto&p:pd){
          num *= (p.second+1);
        }
      }
      dump(i,num);
      if(num==1){
        ans += mint(i);
      }else{
        mint v=num;
        mint ruij = v.pow(N)-1;
        ans += mint(ruij*i);
      }
    }else{
      ans += i;
    }
  }
  cout<<ans<<endl;
#endif
  return 0;
}