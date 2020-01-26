//https://atcoder.jp/contests/dwacon6th-prelims/tasks/dwacon6th_prelims_b
//B - Fusing Slimes
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
constexpr ll MOD=1e9+7;

void test(){
    auto fc=[](ll a,ll b){
        ll tmp=a+b+b+a+b;
        return tmp;
    };
    dump(fc(1,1)); 
    dump(fc(2,1));
    dump(fc(1,2));
    dump(fc(5,1));
    dump(fc(1,5));
    exit(0);
}

void test2(ll nu){
    std::vector<int> v(nu);
    FOR(i,0,nu){
        v.at(i)=i+1;
    }
	do {
		//dump(v);
	} while(std::next_permutation(v.begin(), v.end()));
    exit(0);
}

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
// using ll=int64_t;
// constexpr ll MOD=1e9+7;
using mint = modint<MOD>;

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    //test2(10);
    test();
    ll N; cin>>N;
    vector<ll> xn(N+1);
    FOR(i,1,N+1){
        cin>>xn.at(i);
    }    
    sort(xn.begin(),xn.end());

    vector<ll> dist(N);
    FOR(i,1,N){
        dist.at(i) = xn.at(i+1) - xn.at(i);
    }
    dump(dist);

    mint ans=0;
    mint ev = 1;
    mint mul = 1;
    FOR(i,1,N){
        ans += mul * dist.at(i);
        // ev = ev*i + mul;
        // mul *= i;
        // ans += ev * dist.at(i) + ev*ans;
        dump(ans);
    }
    cout<<ans<<endl;

    return 0;
}