//https://atcoder.jp/contests/abc015/tasks/abc015_4
//D - 高橋くんの苦悩
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
    ll W; cin>>W; //幅
    ll N,K; cin>>N>>K; //数,可能枚数   
    vector<pair<ll,ll>> abn(N+1);
    for(auto&& ab:abn){
        cin>>ab.first>>ab.second;
    }
    vector<vector<vector<ll>>> dp(N+2,vector<vector<ll>>(K+1,vector<ll>(W+1,0)));
    FOR(i,0,N+1){
        FOR(k,0,K+1){
            FOR(w,0,W+1){
                ll a=abn.at(i).first;
                ll b=abn.at(i).second;
                if (w-a>=0 && k-1>=0){
                    dp[i+1][k][w] = max(dp[i][k-1][w-a] + b, dp[i][k][w]); //前の状態から次の状態を計算するように
                }else{
                    dp[i+1][k][w] = dp[i][k][w];
                }
            }
        }
    }
    ll ans=0;
    FOR(k,0,K+1){
        FOR(w,0,W+1){
            ans=max(dp[N][k][w],ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}