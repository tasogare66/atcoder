//AtCoder ABC065 C - Reconciled?
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
constexpr ll MOD=1e9+7;

ll kaijyou(ll a){
    ll ret=1;
    while(a>=1){
        ret=ret*a%MOD;
        --a;
    }
    return ret;
}

int main() {
    ll N,M;
    cin>>N>>M;
    ll ans=0;
    if(N==M||abs(N-M)==1){
        ans = kaijyou(N) * kaijyou(M) % MOD;
        ans = ans * (N==M?2:1) % MOD;
    }
    cout<<ans<<endl;
    return 0;
}