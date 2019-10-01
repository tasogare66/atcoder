//https://atcoder.jp/contests/abc142/tasks/abc142_e
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
    ll N,M; cin>>N>>M; //Mがカギ
    struct Key{
        ll value=0;
        ll flag=0;
        void set(ll c){
            flag |= (1<<(c-1)); //1startなので
        }
        bool check(ll c){
            return (flag&(1<<(c-1)));
        }
    };
    vector<Key> keys(M+1);
    FOR(i,1,M+1){
        auto& k = keys.at(i);
        cin>>k.value;
        ll bn; cin>>bn; //開けれる数
        REP(o,bn){
            ll c; cin>>c;
            k.set(c);
        }
    }
    const ll num_box=12;
    //int dp[num_box+1][1<<(num_box+1)]; //どの箱まで?,flag
    vector<vector<ll>> dp(N+1,vector<ll>(1<<(N+1),INT32_MAX));
    dp[0][0]=0;
    FOR(i,1,N+1){
        for(ll pf=0;pf<(1<<N);++pf){
            if (pf&(1<<(i-1))) {
                dp[i][pf]=min(dp[i-1][pf], dp[i][pf]); 
            } else {
                for(auto& k:keys){
                    if (k.check(i)) {
                        ll nf = k.flag | pf;
                        dp[i][nf]=min<ll>(dp[i-1][pf]+k.value, dp[i][nf]);
                    }
                }
            }
        }
    }
    ll ans=dp[N][(1<<N)-1];
    cout<<(ans>=INT32_MAX?-1:ans)<<endl;
    return 0;
}