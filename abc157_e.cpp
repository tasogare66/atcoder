//https://atcoder.jp/contests/abc157/tasks/abc157_e
//E - Simple String Queries
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

// fenwick_tree<T> t(n)
// サイズ n，型 T の木を作る
// t.sum(l,r)
// [l, r) の和を求める
// t.sum(r) [0, r) の和
// t.add(i,a)
// 0-indexed で i 番目の要素に a を足す
//
// vector<ll> an={1,2,3,4,5};
// fenwick_tree<ll> tmp(an.size());
// FOR(i,0,an.size()){
//     tmp.add(i,an[i]); //add(0,1),add(1,2),add(2,3)...
// }
// FOR(i,0,an.size()+1){
//     dump(i,tmp.sum(i)); //i=0,sum(i)=0, i=1,sum(i)=1, i=2,sum(i)=3,...,i=5,sum(i)=15
// }
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

int main() {
    ll N; cin>>N;
    string S; cin>>S;
    unordered_map<char,fenwick_tree<ll>> tbl;
    for(char c='a';c<='z';++c){
        tbl[c]=fenwick_tree<ll>(N);        
    }
    FOR(i,0,S.size()){
        tbl[S.at(i)].add(i,1);
    }

    auto irekae = [&](ll p,char c){
        --p;
        auto prev=S.at(p);
        tbl[prev].add(p,-1);
        S.at(p)=c;
        tbl[c].add(p,1);
    };
    auto count = [&](ll s,ll e)->ll{
        ll ret=0;
        --s;
        for(const auto& t:tbl){
            if (t.second.sum(s,N) - t.second.sum(e,N)>0) ++ret;
        }
        return ret;
    };

    ll Q; cin>>Q;
    vector<ll> ans;
    REP(i,Q){
        ll t; cin>>t;
        if(t==1){
            ll p; cin>>p;
            char c; cin>>c;
            irekae(p,c);
        }else if(t==2){
            ll l,r;; cin>>l>>r;
            ans.push_back(count(l,r));
        }else{
            assert(0);
        }
    }
    for(const auto& a:ans){
        cout<<a<<endl;
    }


    return 0;
}