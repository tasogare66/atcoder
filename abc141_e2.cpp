//
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    #if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    string S; cin>>S;
    vector<vector<ll>> dp(N+1,vector<ll>(N+1,0)); //dp[i][j],iからとjから始めた一致する最大長さ
    REP(j,N){
        dp[N-1][j]=(S[j]==S[N-1])?1:0;
    }
    for(ll i=N-2;i>=0;--i){
        for(ll j=N-1;j>=0;--j){
            if (S[i]==S[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    ll ans=0;
    for(){

    }

    return 0;
}