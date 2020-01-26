//https://atcoder.jp/contests/past201912-open/tasks/past201912_i
//I - 部品調達 / Procurement
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
    std::ifstream in("./test/sample-3.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N, M; cin>>N>>M;
    vector<pair<ll,ll>> scm(M+1);

    auto s_to_bit = [](const string& s)->ll{
        ll ret=0;
        for(auto c:s){
            ret *= 2;
            if(c=='Y'){
                ret |= 1;
            }
        }
        return ret;
    };
    FOR(i,1,M+1){
        string s; cin>>s;
        ll c; cin>>c;
        scm[i]=make_pair(s_to_bit(s),c);
    }

    ll max_bit = pow(2,N);
    constexpr ll INF=INT64_MAX;
    vector<vector<ll>> dp(M+1,vector<ll>(max_bit,INF));
    dp[0][0]=0;
    FOR(m,1,M+1){
        //使わない場合
        REP(b,max_bit){
            dp[m][b]=dp[m-1][b];
        }
        //使った場合
        const auto& sc=scm[m];
        REP(b,max_bit){
            ll nb=b|sc.first;
            ll prv_c = dp[m-1][b]; 
            if (dp[m-1][b]!=INF){
                dp[m][nb]=min(dp[m-1][b]+sc.second,dp[m][nb]);
            }
        }
    }
    ll ans=dp[M][max_bit-1];
    if (ans==INF) ans=-1;
    cout<<ans<<endl;

    return 0;
}