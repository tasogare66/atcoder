//https://atcoder.jp/contests/code-festival-2017-qualc/tasks/code_festival_2017_qualc_b
//B - Similar Arrays
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
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    ll ttl=pow<ll>(3,N);
    ll sub=1;
    for(const auto& a:an){
        if(a%2==1)sub*=1;
        else sub*=2;
    }
    cout<<ttl-sub<<endl;
    return 0;
}