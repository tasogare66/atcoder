//AtCoder ABC085 B - Kagami Mochi
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N;
    cin>>N;
    vector<ll> dn(N,0);
    for(auto&& d:dn){
        cin>>d;
    }
    sort(dn.begin(),dn.end());
    ll ans=0;
    ll cur=0;
    for(const auto& d:dn){
        if(cur<d){
            cur=d;
           ++ans; 
        }
    }
    cout<<ans<<endl;
    return 0;
}