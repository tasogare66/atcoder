//AtCoder ABC115 C - Christmas Eve
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    ll N,K; cin>>N>>K;
    vector<ll> hn(N);
    for(auto&& h:hn){
		cin >> h;
	}
    sort(hn.begin(),hn.end());
    ll ans=INT64_MAX;
    for(ll i=0;i<=hn.size()-K;++i){
        ll d=hn[i+K-1]-hn[i];
        ans=min(d,ans);
    }
    cout<<ans<<endl;
    return 0;
}