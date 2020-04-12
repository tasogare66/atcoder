//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B&lang=ja
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
int solve(){
  ll n,x; cin>>n>>x;
  if (n==0)return -1;
  ll ans=0;
  FOR(a,1,n+1){
    FOR(b,a+1,n+1) FOR(c,b+1,n+1){
      if(a+b+c==x)++ans;
    }
  }
  cout<<ans<<endl;
  return ans;
}
int main() {
  while(true){
    if (solve()<0)break;
  }
  return 0;
}