//https://atcoder.jp/contests/abc137/tasks/abc137_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll K,X; cin>>K>>X;
    ll minp=max<ll>(X-K+1,-1000000);
    ll maxp=min<ll>(X+K-1,1000000);
    for(ll i=minp;i<=maxp;++i){
        cout<<i<<endl;
    }
    return 0;
}