//https://atcoder.jp/contests/tdpc/tasks/tdpc_number
//E - 数
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
constexpr ll MOD=1e9+7;
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll D; cin>>D;
    string N; cin>>N;

    //[決めた桁][未満フラグ,未満のとき1][]
    const ll modd_max=D+1;
    vector<vector<vector<ll>>> dp(N.size()+1, vector<vector<ll>>(2,vector<ll>(modd_max)));

    dp[0][0][0]=1;
    FOR(k,0,N.size()){
        ll digit = N.at(k)-'0';
        FOR(f,0,modd_max){
            for(ll d=0;d<=9;++d){ //未満フラグ1
                ll mod_d = (f+d)%D;
                dp[k+1][1][mod_d] += dp[k][1][f];
                dp[k+1][1][mod_d] %= MOD;
            }
            for(ll d=0;d<=digit;++d){ //未満フラグ0
                ll mod_d = (f+d)%D;
                dp[k+1][(d<digit)][mod_d] += dp[k][0][f]; //未満フラグ0は桁数があっているとき
                dp[k+1][(d<digit)][mod_d] %= MOD;
            }
        }
    }
    ll ans = dp[N.size()][0][0]+dp[N.size()][1][0]-1; //0の分引く
    ans %= MOD;
    cout<<ans<<endl;

    return 0;
}