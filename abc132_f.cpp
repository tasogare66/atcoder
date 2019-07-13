//AtCoder ABC132 F - Small Products
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
constexpr ll MOD=1e9+7;
constexpr ll nmax=1e5+10;//1e9+10;
ll dp[110][nmax];
//constexpr ll nmax=1e2+10;//1e9+10;
//ll dp[5][nmax];
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-3.in");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,K; cin>>N>>K;
    unordered_map<ll,ll> tbl; //N/jが何種類か
    vector<ll> lim;
    //lim.reserve(N+1); //出てくる数
#if LOCAL&0
    for(ll i=1;i<=N;++i){
         ++tbl[N/i];
    //     lim.push_back(N/i);
    }
#endif
    for(ll i=1;i*i<=N;++i){
        lim.push_back(i);
        lim.push_back(N/i);
    }
    sort(lim.begin(),lim.end(), greater<ll>());
    lim.erase(std::unique(lim.begin(), lim.end()), lim.end()); //重複除く
    lim.insert(lim.begin(), 0);
    for(int i=1;i<lim.size();++i){
        ll l=N/lim[i];
        ll r=lim[i-1]==0?0:N/lim[i-1];
        tbl[lim[i]]=l-r;
    }

    dp[0][1]=1;
    for(ll k=1;k<=K;++k){
		//vector<ll> sum(N + 1,0); //累積和
        vector<ll> sum(lim.size()+10,0);
		//for(ll si = 1; si <= N; ++si) {
        //    sum[si]=sum[si-1]+dp[k-1][si];
		//}
        //unordered_map<ll,ll> sum; //累積和
        for(ll si=1;si<=lim.size();++si){
            sum[si]=sum[si-1]+dp[k-1][si];
        }
        for(ll si=1;si<=lim.size();++si){
            ll sum_range=lim.size()-si;
            ll multip=tbl[lim[si]];
            dp[k][si]=sum[sum_range]*multip%MOD;
        }
		//for(ll m=1;m<=N;++m){
            // for(ll a=1;a<=N/m;++a){
            //     dp[k][a]+=dp[k-1][m];
            // }
        //    dp[k][m]=sum[N/m];
        //}
    }
    // for(ll k=1;k<=K;++k){
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
        ans %= MOD;
    }
    cout<<ans<<endl;
    return 0;
}