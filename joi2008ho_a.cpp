//https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_a
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
  //std::ifstream in("./test/sample-1.in");
  std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll n; cin>>n;
  vector<pair<ll,ll>> ans;
  FOR(i,1,n+1){
    ll c; cin>>c;
    if(i%2==0){ //eve
      if(ans.back().first==c){
        ans.back().second++;
      }else{
        auto tmp=ans.back();
        ans.pop_back();
        tmp.first=c;
        tmp.second++;
        if(ans.size()==0){
          ans.push_back(tmp);
        }else{
          ans.back().second += tmp.second;
        }
      }
    }else{
      //odd
      if(ans.size()==0 || ans.back().first!=c){
        ans.push_back({c,1});
      }else{
        ans.back().second++;
      }
    }
  }
  dump(ans);
  ll result=0;
  for(const auto& p:ans){
    if(p.first==0) result += p.second;
  }
  cout<<result<<endl;
  return 0;
}