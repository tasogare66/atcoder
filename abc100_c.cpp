//AtCoder ABC100 C - *3 or /2
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
ll cnt(ll v){
    ll r=0;
    while(v%2==0){
        v/=2;
        ++r;
    }
    return r;
}
int main() {
    ll N; cin>>N;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    ll ans=0;
    for(const auto& a:an){
        ans += cnt(a);
    }
    cout<<ans<<endl;
    return 0;
}