//https://atcoder.jp/contests/nikkei2019-final/tasks/nikkei2019_final_a
//A - Abundant Resources
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
#if LOCAL&01
  std::ifstream in("./test/sample-1.in");
  //std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll N; cin>>N;
  vector<ll> an(N+1);
  FOR(i,1,N+1){
    cin>>an.at(i);
  }
  vector<ll> sums(N+1);
  FOR(i,1,N+1){
    sums.at(i)=an.at(i)+sums.at(i-1);
  }
  FOR(w,1,N+1){
    ll ans=0;
    FOR(j,w,N+1){
      chmax(ans,sums[j]-sums[j-w]);
    }
    cout<<ans<<endl;
  }

  return 0;
}