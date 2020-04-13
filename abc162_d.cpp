//https://atcoder.jp/contests/abc162/tasks/abc162_d
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
  std::ifstream in("./test/sample-2.in");
  //std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll N; cin>>N;
  string S; cin>>S;
  vector<vector<ll>> rgb(3,vector<ll>());
  constexpr int R=0,G=1,B=2;
  FOR(i,0,S.size()){
    ll p=i+1;
    char c = S.at(i);
    if(c=='R'){
      rgb[R].push_back(p);
    }else if(c=='G'){
      rgb[G].push_back(p);
    }else if(c=='B'){
      rgb[B].push_back(p);
    }
  }
  ll ans=rgb[R].size()*rgb[G].size()*rgb[B].size();
  ll tmp=0;
  FOR(i,0,N){
    FOR(s,1,N){
      ll p0=i,p1=i+s,p2=i+2*s;
      if(p1>=N||p2>=N)break;
      if(S.at(p0)!=S.at(p1) && S.at(p1)!=S.at(p2) && S.at(p0)!=S.at(p2)){
        //dump(p0,p1,p2);
        ++tmp;
      }
    }
  }
  dump(ans, tmp);
  cout<<ans-tmp<<endl;
#if 0
  ll ans=0;
  for(const auto& r:rgb[R]){
    for(const auto& g:rgb[G]){
      for(const auto& b:rgb[B]){
        vector<ll> tmp={r,g,b};
        sort(tmp.begin(),tmp.end());
        if(tmp[1]-tmp[0]!=tmp[2]-tmp[1]){ //j-i != k-j
          ++ans;
        }
      }
    }
  }
  cout<<ans<<endl;
#endif
  return 0;
}