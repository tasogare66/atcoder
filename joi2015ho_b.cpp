//https://atcoder.jp/contests/joi2015ho/tasks/joi2015ho_b
//B - ケーキの切り分け２ (Cake 2)
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
  std::ifstream in("./test/sample-3.in");
  //std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll N; cin>>N;
  vector<ll> an(N);
  for(auto&& a:an){
    cin>>a;
  }
  REP(i,N){//2週目
    an.push_back(an.at(i));
  }
  REP(i,N){//3週目
    an.push_back(an.at(i));
  }

  auto geta = [&](ll p)->ll{
    if(p<0)return -1;
    if(p>=an.size()) return -1;
    return an.at(p);
  };
  vector<vector<ll>> dp(2*N+1,vector<ll>(3*N+1,-1));
  function<ll(ll,ll)> dfs=[&](const ll il, const ll ir)->ll{ //開区間
    if(dp[il][ir]>=0)return dp[il][ir];
    ll l=il, r=ir;
    ll ret=0;
    dump(l,r);
    //IOI多い方とる
    ll lv=geta(l-1);
    ll rv=geta(r);
    if(lv>rv){
      --l;
    }else{
      ++r;
    }
    auto len=r-l;
    if(len>=N)return 0; //ここで取れなかったら戻す
    //JOI
    ll lv2=geta(l-1);
    if(lv2>0) ret = dfs(l-1,r)+lv2;
    ll rv2=geta(r);
    dump(lv2,rv2);
    if(rv2>0) chmax(ret, dfs(l,r+1)+rv2);
    dp[il][ir]=ret;
    return ret;
  };
  //dump(dfs(0,1)+an[0]); return 0;

  ll ans=0;
  FOR(i,N,2*N){
    chmax(ans,dfs(i,i+1)+an.at(i));
  }
  cout<<ans<<endl;

  return 0;
}