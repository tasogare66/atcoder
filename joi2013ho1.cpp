//https://atcoder.jp/contests/joi2013ho/tasks/joi2013ho1
//1 - 電飾 (illumination)
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
//よって、交互列を長さの数字に変換し、最大3つ連続
//する場所の最大値が答えとなる。
//○|○●○|○●|●○●○|○●
//1 3   2  4    2
// [-----------] <-こたえ
int main() {
#if LOCAL&01
  //std::ifstream in("./test/sample-1.in");
  std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll N; cin>>N;
  vector<ll> cn(N);
  for(auto&& c:cn) cin>>c;

  vector<ll> tbl;
  ll p=cn.at(0);
  FOR(i,0,N){
    if(p==cn.at(i)) tbl.push_back(1);
    else tbl.back()++;
    p = cn.at(i);
  }
  ll ans=0;
  FOR(i,0,min<ll>(3,tbl.size())){
    ans += tbl.at(i);
  }
  for(ll i=0;i+2<tbl.size();++i){
    ll tmp=tbl[i]+tbl[i+1]+tbl[i+2];
    chmax(ans,tmp);
  }
  cout<<ans<<endl;
}

int main_() {
#if LOCAL&0
  //std::ifstream in("./test/sample-1.in");
  std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  ll N; cin>>N;
  vector<ll> cn(N);
  for(auto&& c:cn)cin>>c;

  vector<pair<ll,ll>> tbl; //col,num
  tbl.push_back({cn[0],1});
  FOR(i,1,N){
    if(i+1>=N){
      tbl.push_back({cn.at(i),1});
    }else if(tbl.back().first != cn.at(i) && cn.at(i)!=cn.at(i+1)){
      tbl.back().second += 2;
      ++i;
    }else{
      tbl.push_back({cn.at(i),1});
    }
  }
  dump(tbl);
  ll ans=0;
  FOR(i,0,tbl.size()){
    chmax(ans,tbl.at(i).second);
  }

  auto front_count = [&](ll pos){
    ll prev=tbl.at(pos).first^1; //ここはひっくり返す
    ++pos;
    ll result=0;
    do{
      if(pos>=tbl.size()) break;
      if(prev==tbl.at(pos).first) break;
      result += tbl.at(pos).second;
      prev=tbl.at(pos).first;
      ++pos;
    }while(true);
    return result;
  };
  auto back_count = [&](ll pos){
    ll prev=tbl.at(pos).first^1; //ここはひっくり返す
    --pos;
    ll result=0;
    do{
      if(pos<0) break;
      if(prev==tbl.at(pos).first) break;
      result += tbl.at(pos).second;
      prev=tbl.at(pos).first;
      --pos;
    }while(true);
    return result;
  };

  //1
  FOR(i,0,tbl.size()){
    ll tmp=tbl.at(i).second + front_count(i) + back_count(i);
#if 0
    ll c=tbl.at(i).first^1;
    ll tmp=tbl.at(i).second;
    ll prev=c;
    ll f=i+1;
    do{
      if(f>=tbl.size()) break;
      if(prev==tbl.at(f).first) break;
      tmp += tbl.at(f).second;
      prev=tbl.at(f).first;
      ++f;
    }while(true);
    prev=c;
    ll b=i-1;
    do{
      if(b<0) break;
      if(prev==tbl.at(b).first) break;
      tmp += tbl.at(b).second;
      prev=tbl.at(b).first;
      --b;
    }while(true);
#endif
    chmax(ans,tmp);
  }
  //2
  FOR(i,0,tbl.size()-1){
    if(tbl.at(i).first == tbl.at(i+1).first) continue; //同じいろだと無視
    ll tmp=tbl.at(i).second + tbl.at(i+1).second;
    tmp += front_count(i+1);
    tmp += back_count(i);
    chmax(ans,tmp);
  }
  cout<<ans<<endl;

  return 0;
}