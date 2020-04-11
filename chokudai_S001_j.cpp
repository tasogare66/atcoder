//https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_j
//
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

void test(){
    vector<ll> an={1,2,3,4,5};
    fenwick_tree<ll> tmp(5);
    FOR(i,0,an.size()){
        tmp.add(i,an[i]);
    }
    FOR(i,0,an.size()+1){
        dump(i,tmp.sum(i));
    }

    exit(0);
}

int main() {
    //test();

    ll N; cin>>N;
    vector<ll> an(N+1);
    FOR(i,0,N){
        cin>>an.at(i);
    }
    fenwick_tree<ll> bit(N+1);
    ll ans=0;
    FOR(i,0,N){
        auto a=an.at(i);
        ans += i - bit.sum(a);
        dump(i,a,bit.sum(a));
        bit.add(a,1); //1をいれる
        // auto a=an.at(i);
        // ans += bit.sum(a,N);
        // bit.add(a,1); //1をいれる
    }
    cout<<ans<<endl;
    return 0;
}
