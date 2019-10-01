//https://atcoder.jp/contests/abc079/tasks/abc079_d
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll H,W; cin>>H>>W;
    vector<vector<ll>> cij(10,vector<ll>(10));
    vector<vector<ll>> d(10,vector<ll>(10, INT64_MAX)); //warshall_floyd
    REP(y,10){
        REP(x,10){
            ll c; cin>>c;
            cij[y][x]=c;
            auto from = y;
            auto to = x;
            d[from][to]=c;
        }
    }
    vector<vector<ll>> ahw(H,vector<ll>(W));
    for(auto&& ah:ahw){
        for(auto&& a:ah){
            cin>>a;
        }
    }

    auto warshall_floyd = [&](int n) //nは頂点数
    {
	    for(int i = 0; i < n; i++) // 経由する頂点
		    for(int j = 0; j < n; j++) // 開始頂点
			    for(int k = 0; k < n; k++) // 終端
				    d[j][k] = std::min(d[j][k], d[j][i] + d[i][k]);
    };
	warshall_floyd(10); //O(n^3)

    ll ans = 0;
    for(const auto& ah:ahw){
        for(const auto& a:ah){
            if (a!=-1){
                ans += d[a][1];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}