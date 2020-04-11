//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B&lang=ja
//How many ways?
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

ll solve(ll n, ll ix){
    ll cnt=0;
    FOR(x,1,n+1){
        FOR(y,x+1,n+1){
            FOR(z,y+1,n+1){
                if(x+y+z==ix) ++cnt;
            }
        }
    }
    return cnt;
}

int main() {
    vector<ll> ans;
    while(true){
        ll n,x; cin>>n>>x;
        if(n==0) break;
        ans.push_back(solve(n,x));
    }
    for(const auto& a:ans){
        cout<<a<<endl;
    }    
    return 0;
}