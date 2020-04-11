//https://atcoder.jp/contests/judge-update-202004/tasks/judge_update_202004_b
//B - Picking Balls
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
  ll N; cin>>N;
  priority_queue<ll, vector<ll>, greater<ll> > rs;
  priority_queue<ll, vector<ll>, greater<ll> > bs;
  REP(i,N){
    ll x; char c; cin>>x>>c;
    if(c=='B') bs.push(x);
    else rs.push(x);
  }
  while(!rs.empty() || !bs.empty()){
    auto *lst=&bs;
    if(!rs.empty()){
      lst = &rs;
    }
    cout<<lst->top()<<endl;
    lst->pop();
  }

  return 0;
}