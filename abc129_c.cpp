//AtCoder ABC129
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
constexpr ll MOD=1000000007;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,M;
    cin>>N>>M;
    vector<ll> am(M,0);
    unordered_map<ll,int> br;
    for(auto&& a:am){
        cin>>a;
        br.insert(make_pair(a,1));
    }
    vector<ll> dp(N+1);
    dp[0]=1;
    for(int i=1;i<=N;++i){
        if(!br[i-1]) {
            dp[i]+=dp[i-1];
            dp[i]%=MOD;
        }
        if(i-2>=0&&!br[i-2]){
            dp[i]+=dp[i-2];
            dp[i]%=MOD;
        }
    }
    cout<<dp[N]<<endl;
    return 0;
}