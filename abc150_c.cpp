//https://atcoder.jp/contests/abc150/tasks/abc150_c
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
int main() {
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
