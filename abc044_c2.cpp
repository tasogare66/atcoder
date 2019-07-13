//AtCoder ABC044 C - 高橋君とカード / Tak and Cards
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
ll dp[51][51][51*51]={}; //xiまでkまい選んで合計が何組?
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,A; cin>>N>>A;
    vector<ll> xn(N+1,0);
    for(ll i=1;i<=N;++i){
        cin>>xn[i];
    }
    dp[0][0][0]=1;
    for(ll i=1;i<=N;++i){
        for(ll k=0;k<=i; ++k){
            for(ll s=0;s<=N*50;++s){
                dp[i][k][s] = dp[i-1][k][s];
                if (s>=xn[i]&&k>=1){
                    dp[i][k][s] += dp[i-1][k-1][s-xn[i]];
                }
            }
        }
    }
    ll ans=0;
    for(ll k=1;k<=N;++k){
        ans += dp[N][k][k*A];
    }
    cout<<ans<<endl;
    return 0;
}