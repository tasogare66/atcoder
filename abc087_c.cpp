//AtCoder ABC087 C - Candies
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N;
    cin>>N;
    vector<vector<ll>> an(2,vector<ll>(N+1,0));
    for(auto&& at:an){
        for(ll i=1;i<=N;++i){
            cin>>at[i];
        }
    }
    vector<vector<ll>> sumt(2,vector<ll>(N+1,0));
    ll n=0;
    for(auto && sum:sumt){
        ll ttl=0;
        for(int i=1;i<=N;++i){
            ttl+=an[n][i];
            sum[i]=ttl;
        }
        ++n;
    }
    ll ans=0;
    for(ll i=1;i<=N;++i){
        ll num=sumt[0][i]-sumt[0][0] + sumt[1][N]-sumt[1][i-1];
        ans=max(ans,num);
    }
    cout<<ans<<endl;
    return 0;
}