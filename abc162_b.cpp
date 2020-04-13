//https://atcoder.jp/contests/abc162/tasks/abc162_b
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
//o(1)
int main() {
  ll N; cin>>N;
#if 0
  auto sum_func = [&](ll d){
    ll f=d;
    ll l=(N/d)*d;
    ll num=N/d;
    return (f+l)*num/2;
  };
  ll ans=sum_func(1)-sum_func(3)-sum_func(5)+sum_func(15);
#else
  auto sumf = [&](ll n){
    return (1+n)*n/2;
  };
  ll ans=sumf(N)-sumf(N/3)*3-sumf(N/5)*5+sumf(N/15)*15;
#endif
  cout<<ans<<endl;
  return 0;
}
int main_() {
  ll N;cin>>N;
  ll ans=0;
  FOR(i,1,N+1){
    if(i%3==0||i%5==0){
    }else{
      ans += i;
    }
  }
  cout<<ans<<endl;
  return 0;
}