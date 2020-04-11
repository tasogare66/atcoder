//https://atcoder.jp/contests/abc074/tasks/arc083_b
//D - Restoring Road Network
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
  ll N; cin>>N;
  vector<vector<ll>> ann(N,vector<ll>(N));
  REP(i,N){
    REP(j,N){
      cin>>ann[i][j];
    }
  }

  auto g=ann;
  warshall_floyd(g);
  ll ans=0;
  REP(i,N){
    REP(j,N){
      if(ann[i][j]!=g[i][j]){
        ans=-1;
        break;
      }
    }
  }
  if(ans<0) {
    cout<<ans<<endl;
    return 0;
  }

  const int n = g.size();
	for(int i = 0; i < n; i++) // 経由する頂点
		for(int j = 0; j < n; j++) // 開始頂点
			for(int k = 0; k < n; k++) // 終端
				  if (g[j][k] == g[j][i] + g[i][k]){
            if (i!=j&&i!=k) ann[j][k]=0;
          }

  REP(i,N)REP(j,N){
    ans += ann[i][j];
  }
  cout<<ans/2<<endl;

  return 0;
}