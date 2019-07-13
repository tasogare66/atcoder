//AtCoder ABC115 B - Christmas Eve Eve
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    ll N; cin>>N;
    vector<ll> pn(N);
    for(auto&& p:pn){
        cin>>p;
    }
    sort(pn.begin(),pn.end(),greater<ll>());
    ll ans=pn[0]/2;
    for(ll i=1;i<pn.size();++i){
        ans+=pn[i];
    }
    cout<<ans<<endl;
    return 0;
}