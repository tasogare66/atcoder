//AtCoder ABC073 C - Write and Erase
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N;
    cin>>N;
    unordered_map<ll,ll> mp;
    for(ll i=0;i<N;++i){
        ll a;
        cin>>a;
        mp[a]^=1;
    }    
    ll ans=0;
    for(const auto& m:mp){
        ans+=m.second;
    }
    cout<<ans<<endl;
    return 0;
}