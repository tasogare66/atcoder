//https://atcoder.jp/contests/abc110/tasks/abc110_d
//D - Factorization
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
constexpr ll MOD=1e9+7;
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
template< typename T >
using Matrix = vector< vector< T > >;

//n=5000だと
//first{2,5} second{3,4} -> 5000=2^3*5^4
template< typename T >
std::pair<std::vector<T>, std::vector<T>> prime_factor_decomp(T n) {
    std::vector<T> p, e;
    T m = n;
    for (T i = 2; i * i <= n; i++) {
        if (m % i != 0) continue;
        T c = 0;
        while (m % i == 0) c++, m /= i;
        p.push_back(i);
        e.push_back(c);
    }
    if (m > 1) {
        p.push_back(m);
        e.push_back(1);
    }
    return std::make_pair(p, e); //直す?
}

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N, M; cin>>N>>M;    
    auto pfd = prime_factor_decomp(M);
    ll ans=1;
    for(const auto& a:pfd.second){
        Matrix<ll>  dp(N+2,vector<ll>(a+2)); //dp[i][j],i番目にj個ある
        FOR(i,0,N+1){
            dp[i][0]=1;
        }
        REP(i,N){
            FOR(j,1,a+1){
                if (j-a-1>=0){
                    dp[i+1][j]=(dp[i][j]+dp[i+1][j-1]-dp[i][j-a-1]+MOD)%MOD;
                }else{
                    dp[i+1][j]=(dp[i][j]+dp[i+1][j-1])%MOD;
                }
            }
        }
        dump(dp[N][a]);
        ans = ans*dp[N][a]%MOD;
    }
    cout<<ans<<endl;
    return 0;
}