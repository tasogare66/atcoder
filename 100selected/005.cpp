//https://atcoder.jp/contests/abc095/tasks/arc096_a
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
const ll LINF = 0x1fffffffffffffff;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
template<class T>bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1; } return 0;}
int main() {
  ll A,B,C,X,Y; cin>>A>>B>>C>>X>>Y;
  ll ans = X*A+Y*B;
  FOR(c,1,max(X,Y)+1){
    ll y=2*c*C;
    ll a=max(X-c,0LL);
    ll b=max(Y-c,0LL);
    y+=a*A+b*B;
    chmin(ans,y);
  }
  cout<<ans<<endl;
  return 0;
}