//https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_k
//K - 辞書順で何番目？
//https://nemupm.com/blog/2019/03/03/chokudai-speed-run-001/
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

template <class T>
struct fenwick_tree {
    int n;
    std::vector<T> x;
    fenwick_tree(int n_ = 0) : n(n_), x(n + 1, 0) {}
    int size() const { return n; }
    T sum(int r) const {
        T S = 0;
        for (r = r - 1; r >= 0; r = (r & (r + 1)) - 1) S += x[r];
        return S;
    }
    T sum(int l, int r) const { return sum(r) - sum(l); }
    void add(int k, const T &a) {
        for (; k < n; k |= k + 1) x[k] += a;
    }
    void set(int k, const T &a) { add(k, a - sum(k, k + 1)); }
};

constexpr ll MOD=1e9+7;
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }    
    vector<ll> fact(N+1);
    {
        ll v=1;
        FOR(i,1,N+1){
            v = (v*i)%MOD;
            fact[i]=v;
        }
    }
    auto factorial=[&](ll v)->ll{
        return fact.at(v);
    };

    ll ans=1;
    fenwick_tree<ll> bit(N);
    FOR(i,0,N){
        ll a=an.at(i);
        dump(i,a,bit.sum(a));
        ans += ((a-1-bit.sum(a))*factorial(N-i-1))%MOD;
        ans %= MOD;

        bit.add(a,1);
    }
    cout<<ans<<endl;
    return 0;
}