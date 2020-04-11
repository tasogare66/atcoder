//https://atcoder.jp/contests/abc079/tasks/abc079_d
//D - Wall
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

template< typename T >
void warshall_floyd(vector<vector<T>>& d) //nは頂点数
{
  const int n = d.size();
	for(int i = 0; i < n; i++) // 経由する頂点
		for(int j = 0; j < n; j++) // 開始頂点
			for(int k = 0; k < n; k++) // 終端
        if(d[j][i] != LINF && d[i][k] != LINF) //負辺がない場合は不要
				  d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
}

int main() {
  ll H,W; cin>>H>>W;
  vector<vector<ll>> g(10,vector<ll>(10,LINF));
  FOR(i,0,10){
    FOR(j,0,10){
      cin>>g[i][j];
    }
  }

  warshall_floyd(g);

  ll ans=0;
  FOR(i,0,H){
    FOR(j,0,W){
      ll a; cin>>a;
      if(a==-1||a==1)continue;
      ans += g[a][1];
    }
  }
  cout<<ans<<endl;  
  return 0;
}