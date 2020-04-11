//https://atcoder.jp/contests/joi2014yo/tasks/joi2014yo_d
//D - 部活のスケジュール表 (Schedule)
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
constexpr ll MOD=10007;
int main() {
  ll N; cin>>N;
  string S; cin>>S;

  ll bit_max=1LL<<3;
  vector<vector<ll>> dp(N+1,vector<ll>(bit_max));
  auto day_mask=[&](ll d)->ll{
    --d;
    auto c=S.at(d);
    if(c=='J') return 1<<0;
    if(c=='O') return 1<<1;
    return 1<<2;
  };
  dp[0][1]=1; //Jが鍵
  FOR(i,0,N){
    FOR(nexm,1,bit_max){
      if(not(nexm & day_mask(i+1))) continue;
      FOR(curm,1,bit_max){
        if(curm&nexm){
          dp[i+1][nexm] += dp[i][curm];
          dp[i+1][nexm] %= MOD;
        }
      }
    }
  }
  ll ans=0;
  FOR(m,1,bit_max){
    ans+=dp[N][m];
    ans%=MOD;
  }
  cout<<ans<<endl;
  return 0;
}