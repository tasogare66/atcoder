//https://atcoder.jp/contests/abc106/tasks/abc106_b
//B - 105
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
vector< ll > divisor(ll n) {
  vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}
int main() {
    ll N; cin>>N;
    ll ans=0;
    FOR(i,1,N+1){
        if(i%2==0)continue;
        auto vec = divisor(i);
        if(vec.size()==8) ++ans;
    }    
    cout<<ans<<endl;
    return 0;
}