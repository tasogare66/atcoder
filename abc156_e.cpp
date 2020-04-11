//https://atcoder.jp/contests/abc156/tasks/abc156_e
//E - Roaming
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

//https://firiexp.github.io/library/library/modint.html
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
using mint = modint<MOD>;

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-2.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll n,k; cin>>n>>k;
    k = min(n-1, k);

    vector<mint> factorial(2*1e+5+1);
    mint f=1;
    factorial[0]=1;
    FOR(i,1,factorial.size()){
        f *= i;
        factorial.at(i) = f;
    }

    auto ncr = [&](ll nn, ll aa){
#if 01
        mint u = factorial.at(nn) / factorial.at(nn-aa);
        mint s = factorial.at(aa);
        mint r =  u / s;
        return r.val; 
#else
        mint u(1),s(1);
        FOR(i,0,aa){
            u *= (nn-i);
            s *= (i+1);
        }
        mint r =  u / s;
        return r.val; 
#endif
    };
    dump(ncr(10,2));
    dump(ncr(3,0));

    auto nhr = [&ncr](ll nn, ll rr){
        nn=nn+rr-1;
        return ncr(nn,rr); 
    };

    mint ans=0;
    FOR(z,0,k+1){
        mint v0 = ncr(n,z);
        mint v1 = nhr(n-z,z);        
        dump(v0.val,v1.val);
        ans += v0 * v1;
    }
    cout<<ans<<endl;

    return 0;
}