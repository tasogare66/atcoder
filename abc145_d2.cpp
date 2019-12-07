//https://atcoder.jp/contests/abc145/tasks/abc145_d
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

            //a=333333,b=333333
const int MAX = 510000*10;
const int MOD = 1000000007;
long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// int main() {
//     // 前処理
//     COMinit();
//     // 計算例
//     cout << COM(100000, 50000) << endl;
//                 a=333333,b=333333
// }
int main() {
    COMinit();
#if LOCAL&0
    std::ifstream in("./test/sample-3.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll X,Y; cin>>X>>Y;
    ll ans=0;
#if 1
    do{
        ll tmp=2*Y-X;
        if(tmp%3!=0) break;
        ll a=tmp/3;
        ll b=Y-2*a;
        if (a>=0&&b>=0){
			dump(a, b);
			ans = COM(a + b, a);
        }
    }while(0);
#else
    FOR(a,0,max(X+1,Y+1)){
        ll b=Y-2*a;
        if (b>0){
            if(X==a+2*b){
                //ans
                dump(a,b);
                ans+=COM(a+b, a);
            }
        }
    }    
#endif
    cout<<ans<<endl;
    return 0;
}