//https://atcoder.jp/contests/abc021/tasks/abc021_d
//D - 多重ループ
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

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

int main() {
  ll N,K; cin>>N>>K;

  auto ncr = [](ll n,ll r)->mint{
    mint a=1,b=1;
    REP(i,r){
      a *=(n-i);
    }
    REP(i,r){
      b *=(i+1);
    }
    return a/b;
  };
//  auto ans = ncr(N+K-1,K); //重複組み合わせ
  auto ans = mint::nCr(N+K-1,K);
  cout<<ans<<endl;
  return 0;
}