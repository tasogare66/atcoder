//https://atcoder.jp/contests/abc042/tasks/arc058_b
//D - いろはちゃんとマス目 / Iroha and a Grid
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
//constexpr ll MOD=1e9+7;

const int MAX = 510000;
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

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll H,W,A,B; cin>>H>>W>>A>>B;
    COMinit();
    ll ans = 0;
    ll h1=H-A-1;
    ll w1=B;
    ll h2=A-1;
    ll w2=W-B-1;
    for(ll i=0;i<W-B;++i){
        //h1+w1+i C h1
        //h2+w1-i C h2
        ll a = COM(h1+w1+i,h1);
        ll b = COM(h2+w2-i,h2);
        ans = ans + (a * b)%MOD;
        ans %= MOD;
    }
    cout<<ans<<endl;
    return 0;
}
#if 0
int main() {
    int dp[3][100002]={};
    //int dp[3][10]={};
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll H,W,A,B; cin>>H>>W>>A>>B;
    ll px=0,xx=0;
    dp[px][H] = 1;
    for(ll x=W;x>=1;--x){
        px=xx;
        xx=(xx+1)%3;
        for(ll y=H;y>=1;--y){
            if (x<=B && H-y+1<=A) {
                dp[xx][y] = 0;
                continue;
            }
            dp[xx][y] = (dp[px][y] + dp[xx][y+1])%MOD;
            //cout<<dp[xx][y]<<":"<<dp[px][y]<<","<<dp[xx][y+1]<<endl;
        }
    }
    cout<<dp[xx][1]<<endl;
    return 0;
}
#endif