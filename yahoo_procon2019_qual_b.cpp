//https://atcoder.jp/contests/yahoo-procon2019-qual/tasks/yahoo_procon2019_qual_b
//B - Path
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
    ll e=3,n=4;
    vector<ll> num(n+1);
    REP(i,e){
        ll a,b; cin>>a>>b;
        num.at(a)++;
        num.at(b)++;
    }
    bool ans=true;
    FOR(i,1,n+1){
        if(num.at(i)>2)ans=false;
    }
    cout<<(ans?"YES":"NO")<<endl;
    return 0;
}