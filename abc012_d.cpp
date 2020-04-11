//https://atcoder.jp/contests/abc012/tasks/abc012_4
//D - バスと避けられない運命
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
  ll N,M; cin>>N>>M;
  vector<vector<ll>> g(N+1,vector<ll>(N+1,LINF));
  REP(i,M){
    ll a,b,t; cin>>a>>b>>t;
    g[a][b]=t;
    g[b][a]=t;
  }
  FOR(i,1,N+1){
    g[i][i]=0;
  }

  warshall_floyd<ll>(g);
  vector<ll> wt(N+1,0);
  FOR(s,1,N+1){
    FOR(p,1,N+1){
      chmax(wt.at(s), g[s][p]);
    }
  }

  ll ans=LINF;
  FOR(i,1,N+1){
    ans=min(ans,wt[i]);
  }
  cout<<ans<<endl;

  return 0;
}