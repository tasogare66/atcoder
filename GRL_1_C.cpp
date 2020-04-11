//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja
//全点対間最短経路
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
using Matrix = vector< vector< T > >;
template< typename T>
Matrix<T> make_matrix(ll y, ll x, T v={}){
  return Matrix<T>(y, vector<T>(x,v));
}

void warshall_floyd(int n, Matrix<ll>& d) //nは頂点数
{
	for(int i = 0; i < n; i++) // 経由する頂点
		for(int j = 0; j < n; j++) // 開始頂点
			for(int k = 0; k < n; k++) // 終端
        if(d[j][i] != LINF && d[i][k] != LINF)
				  d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
}

int main() {
  ll V,E; cin>>V>>E;
  Matrix<ll> g = make_matrix<ll>(V,V,LINF);
  REP(i,E){
   ll a,b,c; cin>>a>>b>>c;
   g[a][b]=c; 
  }
  REP(i,V){
    g[i][i]=0;    
  }

  warshall_floyd(V,g);
  dump(g);

  //ある頂点vから頂点v（それ自身)への最短距離が負になれば、Gに負の閉路が存在すると判断できる。
  REP(i,V){
    if(g[i][i]<0){
      cout<<"NEGATIVE CYCLE"<<endl;
      return 0;
    }
  }

  REP(y,V) {
    REP(x,V) {
      if(x!=0)cout<<" ";
      ll v=g[y][x];
      if(v==LINF){
        cout<<"INF";
      }else{
        cout<<g[y][x];
      }
    }
    cout<<endl;
  }

  return 0;
}