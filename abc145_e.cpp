//https://atcoder.jp/contests/abc145/tasks/abc145_e
//E - All-you-can-eat
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

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    //std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N, T; cin>>N>>T;    
    vector<vector<ll>> dp(N+3,vector<ll>(T+2,0));

    vector<pair<ll,ll>> abn(N+1); //time,value
    FOR(i,1,N+1){
        auto& ab=abn.at(i);
        cin>>ab.first>>ab.second;
    }
    sort(abn.begin()+1,abn.end());
    //(*(abn.end()-1)).second=1; //最後は1でいけるとする

    //DP1[i][j] = 1～i 番目の料理で j 分以内に完食できる美味しさの合計の最大値
    for(ll i=1; i<N;++i){
        auto ti=abn.at(i).first;
        auto vi=abn.at(i).second;
        for(ll t=0;t<T; ++t){
            if (t-ti>=0) {
                dp[i][t]=max(dp[i-1][t-ti]+vi, dp[i-1][t]);
            }else{
                dp[i][t]=dp[i-1][t];
            }
        }
        // if(i==N){//最後は0でいけるとする
        //     dp[i][T]=max(dp[i-1][T-1]+vi,dp[i][T]);
        // }
    }

    ll ans=0;
    FOR(i,1,N+1){
        ans=max(dp[i-1][T-1]+abn.at(i).second, ans); //ここみたい
    }
    cout<<ans<<endl;

    return 0;
}
