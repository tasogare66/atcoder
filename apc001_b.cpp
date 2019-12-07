//https://atcoder.jp/contests/apc001/tasks/apc001_b
//B - Two Arrays
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
#if LOCAL&01
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<ll> an(N),bn(N);
    for(auto&& a:an){
        cin>>a;
    }
    for(auto&& b:bn){
        cin>>b;
    }
    // sort(an.begin(),an.end());
    // sort(bn.begin(),bn.end());
    ll a_rest=0;
    REP(i,N){
        auto a=an.at(i);
        auto b=bn.at(i);
        a_rest += max((a-b)*2,0LL);
    }
    REP(i,N){
        auto a=an.at(i);
        auto b=bn.at(i);
        auto tmp=max(b-a,0LL)/2;
        a_rest -= tmp*2;
    }
    cout<<(a_rest<=0?"Yes":"No")<<endl;
    return 0;
}