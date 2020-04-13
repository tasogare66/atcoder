//https://atcoder.jp/contests/abc162/tasks/abc162_a
//A - Lucky 7
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
  string N; cin>>N;
  cout<<(find(N.begin(),N.end(),'7')!=N.end()?"Yes":"No")<<endl;
  return 0;
}
int main_() {
  string N; cin>>N;
  bool ans=false;
  for(auto& c:N){
    if(c=='7') ans=true;
  }
  cout<<(ans?"Yes":"No")<<endl;
  return 0;
}