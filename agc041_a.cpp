//https://atcoder.jp/contests/agc041/tasks/agc041_a
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
    ll N,A,B; cin>>N>>A>>B;
    if(A>B) swap(A,B);
    ll ans=0;
    if(abs(B-A)%2==0) {
        ans= abs(B-A)/2;
    }else{
        //l
        auto l=A-1;
        //r
        auto r=N-B;
        ans += min(l,r);
        ans += 1;
        --B;
        ans+=(B-A)/2;
    }
    cout<<ans<<endl;
    return 0;
}