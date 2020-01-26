//https://atcoder.jp/contests/abc148/tasks/abc148_d
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
    ll c=1;
    ll ans=0;
    FOR(i,0,N){
        ll a=an.at(i);
        if(c==a){
            ++c;
        }else{
            ++ans;
        }
    }
    if(c==1)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}