//https://atcoder.jp/contests/joi2020yo1c/tasks/joi2020_yo1c_a
//A - X に最も近い値 (The Nearest Value)
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
    ll X,L,R; cin>>X>>L>>R;
    ll ans= 0;
    if(L<=X&&R>=X){
        ans=X;
    }else{
        if(abs(X-L)<abs(X-R)){
            ans=L;
        }else{
            ans=R;
        }
    }    
    cout<<ans<<endl;
    return 0;
}