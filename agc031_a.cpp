//AtCoder AGC031 A - Colorful Subsequence
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
constexpr ll MOD=1e9+7;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    string S; cin>>S;
    unordered_map<char,ll> chnum;
    REP(i,N){
        ++chnum[S[i]];
    }
    ll ans=1;
    for(const auto& cn:chnum){
        ans *= (cn.second+1);
        ans %= MOD;
    }
    ans -= 1;
    cout<<ans<<endl;
    return 0;
}