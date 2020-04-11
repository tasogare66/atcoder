//https://atcoder.jp/contests/abc149/tasks/abc149_b
//B - Greedy Takahashi
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
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll A,B,K; cin>>A>>B>>K;    
    ll a=max(A-K,0LL);
    ll rest=max(K-(A-a),0LL);
    ll b=max(B-rest,0LL);
    cout<<a<<" "<<b<<endl;
    return 0;
}
#if 0//2回目
int main() {
  ll A,B,K; cin>>A>>B>>K;
  ll a=A,b=B;
  a = max(A-K,0LL);
  K -= A;  
  if (K>0) {
    b = max(B-K,0LL);
  }
  cout<<a<<" "<<b<<endl;
  return 0;
}
#endif