//AtCoder ABC034 C - 経路
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    lli w,h;
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>w>>h;
    //->w-1,h-1
    //w+h-2Cw-1
    //(w+h-2)!/(h-1)!(w-1)!
    //(w+h-2)! * ((h-1)!)^(p-2) * ((w-1)!)^(p-2)
    COMinit();
    auto ans = COM(w+h-2,w-1);
    cout<<ans<<endl;
    return 0;
}

#if 0
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
  ll W,H; cin>>W>>H;
  --W;--H;
  mint a=1,b=1;
  REP(i,H){
    a *=(W+H-i);
  }
  REP(i,H){
    b *=i+1;
  }
  auto ans=a/b;
  cout<<ans<<endl;
  return 0;
}
#endif