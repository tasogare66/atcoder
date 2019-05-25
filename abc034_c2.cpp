//AtCoder ABC034 C - 経路
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

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
    lli w,h;
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>w>>h;
    //->w-1,h-1
    //w+h-2Cw-1
    //(w+h-2)!/(h-1)!(w-1)!
    //(w+h-2)! * ((h-1)!)^(p-2) * ((w-1)!)^(p-2)
    COMinit();
    auto ans = COM(w+h-2,w-1);
    cout<<ans<<endl;
    return 0;
}