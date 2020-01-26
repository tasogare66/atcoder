//https://atcoder.jp/contests/joi2020yo2/tasks/joi2020_yo2_d
//D - テンキー (Tenkey)
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
using Mat = vector<vector<ll>>;
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll M,R; cin>>M>>R;
    Mat mat(10,vector<ll>(10,INT32_MAX));
    auto setpath = [&](ll a,ll b){
        mat.at(a).at(b) = 1;
        mat.at(b).at(a) = 1;
    };
    REP(i,10){
        mat.at(i).at(i)=0;
    }
    for(ll i=1;i<=7;i+=3){
        setpath(i,i+1);
        setpath(i+1,i+2);
    }
    for(ll i=1;i<=3;++i){
        setpath(i,i+3);
        setpath(i+3,i+6);
    }
    setpath(0,1);
    auto warshall_floyd = [&](int n) //nは頂点数
    {
	    for(int i = 0; i < n; i++) // 経由する頂点
		    for(int j = 0; j < n; j++) // 開始頂点
			    for(int k = 0; k < n; k++) // 終端
				    mat[j][k] = std::min(mat[j][k], mat[j][i] + mat[i][k]);
    };
	warshall_floyd(10); //O(n^3)

    ll ans=INT64_MAX;
    auto calc_count=[&](ll v)->ll{
        if (v==0) return 1;
        ll cnt=0;
        ll pk=-1;
        while(v>0){
            auto k=v%10;
            v/=10;
            ++cnt;
            if (pk>=0) cnt += mat[pk][k];
            pk = k;
        }        
        cnt += mat[pk][0];
        return cnt;
    };
#if 0
    //test
    REP(i,10){
        dump(i,calc_count(i));
    }
    dump(calc_count(125));
    dump(calc_count(943));
#endif
    FOR(t,0,1e+6){
        ll i=R+M*t;
        chmin(ans,calc_count(i));
    }
#if 0
    for(ll i=R;;i+=M){
        chmin(ans,calc_count(i));

        ll tmp=i;
        ll keta=0;
        while(tmp>0){
            tmp/=10;
            ++keta;
        }
        if (ans<=keta) break;
    }
#endif
    cout<<ans<<endl;
    return 0;
}