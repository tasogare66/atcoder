//AtCoder ABC074 B - Collecting Balls (Easy Version)
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N,K;
    cin>>N>>K;
    vector<ll> atbl(N);
    for(auto&& a:atbl){
        cin>>a;
    }
    ll ans=0;
    for(const auto& a:atbl){
        ans += (min(abs(a-0),abs(a-K))*2);
    }
    cout<<ans<<endl;
    return 0;
}