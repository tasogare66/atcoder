//https://atcoder.jp/contests/abc150/tasks/abc150_c
//C - Count Order
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
    vector<ll> pn(N);
    for(auto&& p:pn){ cin>>p; }
    vector<ll> qn(N);
    for(auto&& q:qn){ cin>>q; }

    vector<ll> fact(N+1);
    fact.at(1)=1;
    FOR(i,2,N+1){
        fact.at(i)=fact.at(i-1)*i;
    }

    auto lambda_count = [&](const auto& vec){
        ll result=0;
        fenwick_tree<ll> bit(N+1);
        FOR(i,0,vec.size()){
            ll va = vec.at(i);
#if LOCAL
            ll cnt=0;
            FOR(j,i+1,vec.size()){
                if(va>vec.at(j)) ++cnt;
            }
#endif
            ll cnt2 = va-1-bit.sum(va);
            result += (fact.at(N-i-1)*cnt2);
            dump(N-i,cnt,result,cnt2);

            bit.add(va,1);
        }
        return result+1;
    };
    //dump(lambda_count(vector<ll>{1,2,3}));

    ll a=lambda_count(pn);
    ll b=lambda_count(qn);
    dump(a,b);
    ll ans=abs(a-b);
    cout<<ans<<endl;

    return 0;
}

//組み合わせを全探索
int main__() {
    ll N; cin>>N;
    vector<ll> pn(N);
    vector<ll> qn(N);
    for(auto&& p:pn){
        cin>>p;
    }
    for(auto&& q:qn){
        cin>>q;
    }

    vector<ll> v(N);
    FOR(i,0,N){
        v[i]=i+1;
    }
    ll a=-1;
    ll b=-1;
    ll no=0;
	do {
        ++no;
        dump(v);
        if (a<0 && pn==v) a=no;
        if (b<0 && qn==v) b=no;
	} while(std::next_permutation(v.begin(), v.end()));

    cout<<abs(a-b)<<endl;

	return 0;
}
