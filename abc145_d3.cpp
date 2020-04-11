//https://atcoder.jp/contests/abc145/tasks/abc145_d
//D - Knight
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
#if LOCAL&0
  std::ifstream in("./test/sample-1.in");
  //std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll X,Y; cin>>X>>Y;
  ll bb=(2*X-Y)/3;
  ll aa=X-2*bb;
  ll ab=aa+bb;
  dump(aa,bb,ab);

  if (X!=aa+2*bb || Y!=2*aa+bb || aa<0 || bb<0){
    cout<<0<<endl;
    return 0;
  }

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

  auto ans=ncr(ab,aa);
  cout<<ans<<endl;
  return 0;
}