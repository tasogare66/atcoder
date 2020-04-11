//https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_e
//E - Colorful Hats 2
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
constexpr ll MOD=1e9+7;
#if 0 //二回目
int main() {
  ll N; cin>>N;
  vector<ll> an(N);
  for(auto&& a:an) cin>>a;
  vector<ll> num(3);
  ll ans=1;
  for(const auto& a:an){
    ll mul=0; //みつからないと0になる
    FOR(i,0,3){
      if(num[i]==a) ++mul;
    }
    FOR(i,0,3){
      if(num[i]==a) {
        ++num[i];
        break;
      }
    }
    ans *= mul;
    ans %= MOD;
  }
  cout<<ans<<endl;
  return 0;
}
#endif
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
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
    ll ans=1;
    ll x=0,y=0,z=0;
    FOR(i,0,N){
        auto c=an.at(i);
        ll mul=0;
        if(x==c) ++mul;
        if(y==c) ++mul;
        if(z==c) ++mul;
        if(x==c) {
            ++x;
        } else if(y==c) {
            ++y;
        } else if(z==c) {
            ++z;
        }else {
            cout<<0<<endl;
            exit(0);
        }
        ans *= mul;
        ans %= MOD;
    }
    cout<<ans<<endl;
    return 0;
}