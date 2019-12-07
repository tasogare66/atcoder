//https://atcoder.jp/contests/tdpc/tasks/tdpc_contest
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
template< typename T >
using Matrix = vector< vector< T > >;
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<ll> pn(N+2,0);
    ll max_p=0;
    FOR(i,1,N+1){
        ll p; cin>>p;
        max_p=max(max_p,p);
        pn.at(i)=p;
    }
    Matrix<ll> dp(N+1,vector<ll>((N+1)*max_p+10,0));
    dp[0][0]=1;
    FOR(i,0,N){
        ll add_p=pn.at(i+1);
        dump(add_p);
        FOR(s,0,dp[0].size()){
            dp[i+1][s]=max(dp[i][s],dp[i+1][s]);
             if(s+add_p<dp[0].size()) {
                dp[i+1][s+add_p]=max(dp[i][s],dp[i+1][s+add_p]);
            }
        }
    }
    ll ans=0;
    REP(i,dp[0].size()){
        ans += dp[N][i];
    }
    cout<<ans<<endl;
    return 0;
}