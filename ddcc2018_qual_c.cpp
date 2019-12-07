//https://atcoder.jp/contests/ddcc2019-qual/tasks/ddcc2018_qual_c
//C - チップ・ストーリー　～白銀編～
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
template<class T>bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1; } return 0;}

template <std::uint_fast64_t Modulus> class modint {
    using u64 = std::uint_fast64_t;
public:
    u64 a;
    constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
    constexpr u64 &value() noexcept { return a; }
    constexpr const u64 &value() const noexcept { return a; }
    constexpr modint operator+(const modint rhs) const noexcept {
        return modint(*this) += rhs;
    }
    constexpr modint operator-(const modint rhs) const noexcept {
        return modint(*this) -= rhs;
    }
    constexpr modint operator*(const modint rhs) const noexcept {
        return modint(*this) *= rhs;
    }
    constexpr modint operator/(const modint rhs) const noexcept {
        return modint(*this) /= rhs;
    }
    constexpr modint &operator+=(const modint rhs) noexcept {
        a += rhs.a;
        if (a >= Modulus) {
            a -= Modulus;
        }
        return *this;
    }
    constexpr modint &operator-=(const modint rhs) noexcept {
        if (a < rhs.a) {
            a += Modulus;
        }
        a -= rhs.a;
        return *this;
    }
    constexpr modint &operator*=(const modint rhs) noexcept {
        a = a * rhs.a % Modulus;
        return *this;
    }
    constexpr modint &operator/=(modint rhs) noexcept {
        u64 exp = Modulus - 2;
        while (exp) {
        if (exp % 2) {
            *this *= rhs;
        }
        rhs *= rhs;
        exp /= 2;
        }
        return *this;
    }
    friend ostream& operator<<(ostream& os, const modint& dt){
        os<<dt.a;
        return os;
    }
};
constexpr ll MOD=1e9+7;
using mint = modint<MOD>;

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-4.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    ll tmp=sqrt(N);
    dump(N,tmp);

    auto pow_func=[](ll a,ll n)->mint{
        mint ret=1;
        REP(i,n){
            ret *= a;
        }
        return ret;
    };
    mint ans=pow_func(tmp,20); //sqrt(N)まで
    FOR(i,tmp+1,N+1){
        ll j=N/i;
        dump(i,j);
    }
    cout<<ans<<endl;
    return 0;
}