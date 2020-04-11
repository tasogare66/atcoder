//https://atcoder.jp/contests/judge-update-202004/tasks/judge_update_202004_c
//C - Numbering Blocks
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
#if LOCAL&0
  std::ifstream in("./test/sample-2.in");
  //std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll a1, a2, a3; cin>>a1>>a2>>a3;
  ll N=a1+a2+a3;
 
  // 昇順にソート済みの入力
  std::vector<int> v;
  FOR(i,1,N+1){
    v.push_back(i);
  }

  ll ans=0;
  vector<vector<ll>> mat(4,vector<ll>(4,-1));
  do {
    ll pt=0;
    REP(i,a1){
      mat[0][i]=v.at(pt++);
    }
    REP(i,a2){
      mat[1][i]=v.at(pt++);
    }
    REP(i,a3){
      mat[2][i]=v.at(pt++);
    }
    assert(v.size()==pt);
    auto check_val = [](ll v0, ll v1){
      if(v0<0)return false;
      if(v1<0)return false;
      return true;
    };
    auto check_tbl = [&](){
      FOR(x,0,3){
        FOR(y,0,3){
          if(check_val(mat[x][y+1],mat[x][y])){
            if(mat[x][y+1]<=mat[x][y]){
              return;
            }
          }
          if(check_val(mat[y+1][x],mat[y][x])){
            if(mat[y+1][x]<=mat[y][x]){
              return;
            }
          }
        }
      }
      ++ans;
      dump(mat);
    };
    check_tbl();
  } while (std::next_permutation(v.begin(), v.end()));
  cout<<ans<<endl;
  return 0;
}