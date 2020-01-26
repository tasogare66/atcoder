//https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_b
//B - Problem Set
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
    unordered_map<ll,ll> dn;
    REP(i,N){
        ll D; cin>>D;
        dn[D]++;
    }
    ll M; cin>>M;
    bool ans=true;
    REP(i,M){
        ll T; cin>>T;
        if (dn.count(T) > 0 && dn[T]>0){
            dn[T]-=1;
        } else {
            ans=false;
            break;
        }
    }
    cout<<(ans?"YES":"NO")<<endl;
    return 0;
}