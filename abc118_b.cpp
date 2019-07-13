//AtCoder ABC118 B - Foods Loved by Everyone
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    ll N,M; cin>>N>>M;
    unordered_map<ll,ll> fnmap;
    for(ll i=0;i<N;++i){
        ll k; cin>>k;
        for(ll ai=0;ai<k;++ai){
            ll a; cin>>a;
            ++fnmap[a];
        }
    }
    ll ans=0;
    for(const auto& fn:fnmap){
        if(fn.second==N) ++ans;
    }
    cout<<ans<<endl;
    return 0;
}