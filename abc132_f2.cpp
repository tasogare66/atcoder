//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
constexpr ll MOD=1e9+7;
//constexpr ll nmax=1e5+10;//1e9+10;
//ll dp[101][nmax];
constexpr ll nmax=1e2+10;//1e9+10;
ll dp[5][nmax];
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-2.in");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,K; cin>>N>>K;
    unordered_map<ll,ll> tbl;
    vector<ll> lim;
    for(ll i=1;i<=N;++i){
        ++tbl[N/i];
    }

    dp[0][1]=1;
    for(ll k=1;k<=K;++k){
		vector<ll> sum(N + 1,0); //累積和
		for(ll si = 1; si <= N; ++si) {
            sum[si]=sum[si-1]+dp[k-1][si];
		}
        for(ll si=1;si<=N;++si){
            dp[k][si]=sum[N/si];
        }
		//for(ll m=1;m<=N;++m){ //累積和の前
            // for(ll a=1;a<=N/m;++a){
            //     dp[k][a]+=dp[k-1][m];
            // }
        //    dp[k][m]=sum[N/m];
        //}
    }
    // for(ll k=1;k<=K;++k){ //積がnをこえないののdp,誤読
    //     for(ll m=1;m<=N;++m){
    //         for(ll a=1;a<=N/m;++a){
    //             ll val=m*a;
    //             dp[k][val]+=dp[k-1][m];
    //         }
    //     }
    // }
    ll ans=0;
    for(auto&& v:dp[K]){
        ans += v;
    }
    cout<<ans<<endl;
    return 0;
}