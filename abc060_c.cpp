//AtCoder ABC060 C - Sentou
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N,T;
    cin>>N>>T;
    vector<ll> tbl(N,0);
    for(auto&& t:tbl){
        cin>>t;
    }
    ll ans=T;//最後の人
    for(ll i=1;i<N;++i){
        ans += min(T,tbl[i]-tbl[i-1]);
    }
    cout<<ans<<endl;
    return 0;
}