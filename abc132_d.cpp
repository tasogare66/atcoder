//AtCoder ABC132 D - Blue and Red Balls
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
constexpr ll MOD=1e9+7;

const int MAX = 2000*2;
//const int MOD = 1000000007;
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
    ll N,K; cin>>N>>K;    
    COMinit();
    for(ll i=1;i<=K;++i){
        ll r=N-K;
        ll rin=r+1;
        ll c1=COM(rin,i);
        ll c2=COM(K-1,i-1);
        ll ans=(c1*c2)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}