//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1149&lang=jp
//Problem C: ケーキカット
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
int solve(){
  ll n,w,d; cin>>n>>w>>d;
  if(n==0&&w==0) return 0;
  struct info{
    info()=default;
    info(ll iw,ll id)
      :w(iw)
      ,d(id)
    {
      s=w*d;
    }
    ll w,d;
    ll s;
  };
  vector<info> infos;
  infos.emplace_back(w,d);
  REP(i,n){
    ll p,s; cin>>p>>s;
    --p;
    auto tmp=infos.at(p);
    infos.erase(infos.begin()+p);
    //わける
    auto cut_tate =[&](ll x){
      ll x0=tmp.w-x;
      assert(x0>0);
      ll x1=x;
      if(x0<x1)swap(x0,x1);
      infos.emplace_back(x1,tmp.d);
      infos.emplace_back(x0,tmp.d);
    };
    auto cut_yoko = [&](ll y){
      ll y0=tmp.d-y;
      assert(y0>0);
      ll y1=y;
      if(y0<y1)swap(y0,y1);
      infos.emplace_back(tmp.w,y1);
      infos.emplace_back(tmp.w,y0);
    };

    do{
      ll sss = s % (tmp.w+tmp.d);
      if(sss<tmp.w){
        cut_tate(sss);
        break;
      }
      sss-=tmp.w;
      if(sss<tmp.d){
        cut_yoko(sss);
        break;
      }
      sss-=tmp.d;
    }while(false);
    assert(infos.size()==i+2);
  }
  sort(infos.begin(),infos.end(),[](auto&a,auto&b){ return a.s < b.s;});
  FOR(i,0,infos.size()){
    if(i!=0)cout<<" ";
    cout<<infos.at(i).s;
  }
  cout<<endl;
  return 1;  
}
int main() {
#if LOCAL&01
  //std::ifstream in("./test/sample-1.in");
  std::ifstream in("./input.txt");
  std::cin.rdbuf(in.rdbuf());
#else
  cin.tie(0);
  ios::sync_with_stdio(false);
#endif
  while(solve()!=0){
  }
  return 0;
}