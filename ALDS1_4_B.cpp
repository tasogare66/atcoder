//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B&lang=ja
//ALDS1_4_B
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
    ll n; cin>>n;
    vector<ll> S(n);
    for(auto&& s:S){
        cin>>s;
    }
    sort(S.begin(),S.end());
    ll q; cin>>q;
    vector<ll> T(q);
    for(auto&& t:T){
        cin>>t;
    }    
    ll ans=0;
    for(const auto& t:T){
        auto it = lower_bound(S.begin(),S.end(),t);
        if(it != S.end()) {
            if(*it==t) ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}