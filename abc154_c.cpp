//https://atcoder.jp/contests/abc154/tasks/abc154_c
//C - Distinct or Not
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
    sort(an.begin(),an.end());
    bool ans=true; //yes
    FOR(i,1,N){
        if(an.at(i-1)==an.at(i)) {
            ans=false;
            break;
        }
    }
    cout<<(ans?"YES":"NO")<<endl;    
    return 0;
}