//AtCoder ABC092 B - Chocolate
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N;
    cin>>N;
    ll D,X;
    cin>>D>>X;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    ll ans=X;
    for(const auto& a:an){
        ans+=(D-1)/a+1;
    }
    cout<<ans<<endl;
    return 0;
}