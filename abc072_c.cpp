//AtCoder ABC072 C - Together
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N;
    cin>>N;
    vector<ll> atbl(N);
    for(auto&& a:atbl){
        cin>>a;
    }    
    unordered_map<ll,ll> mp;
    for(const auto& a:atbl){
        mp[a]++;
        mp[a-1]++;
        mp[a+1]++;
    }
    ll ans=0;
    for(const auto&m: mp){
        ans=max<ll>(ans,m.second);
    }
    cout<<ans<<endl;
    return 0;
}