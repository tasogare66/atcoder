//https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_c
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
int main(){ 
  using ld = long double;
  ld eps=1e-14;
  //ld eps=LDBL_EPSILON;
  dump(eps,FLT_EPSILON,DBL_EPSILON,LDBL_EPSILON);
  ld a,b,c; cin>>a>>b>>c;
  if (sqrtl(a)+sqrtl(b)-sqrtl(c)<-eps) {
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}
int main_() {
  constexpr double e = std::numeric_limits<double>::epsilon();
#if LOCAL&01
  std::ifstream in("./test/sample-1.in");
  //std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll a,b,c; cin>>a>>b>>c;
  ll tmp=a+b-c;
  long double ld=(long double)tmp+2*sqrtl(a*b); 
  dump(tmp,ld);
  if(ld<0){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
  
  return 0;
}