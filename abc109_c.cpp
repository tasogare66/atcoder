//AtCoder ABC109 C - Skip
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N,X; cin>>N>>X;
    vector<ll> xn(N);
    for(auto&& x:xn){
        cin>>x;
        x=abs(x-X);
    }
    //gcd
    ll ans=xn[0];
    for(ll i=1;i<xn.size();++i){
        ans=__gcd(ans,xn[i]);
    }
    cout<<ans<<endl;
    return 0;
}
