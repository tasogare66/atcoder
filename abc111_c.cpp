//AtCoder ABC111 C - /\/\/\/
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll n; cin>>n;
    vector<ll> vod; vod.reserve(n/2+1);
    vector<ll> vev; vev.reserve(n/2+1);
    unordered_map<ll,ll> map_od;
    unordered_map<ll,ll> map_ev;
    for(ll i=0;i<n;++i){
        ll v;
        cin>>v;
        if(i%2==0){
            vev.push_back(v);
            ++map_ev[v];
        } else {
            vod.push_back(v);
            ++map_od[v];
        }
    }
    vector<pair<ll,ll>> u_od(map_od.size());
    copy(map_od.begin(),map_od.end(),back_inserter(u_od));
    vector<pair<ll,ll>> u_ev(map_ev.size());
    copy(map_ev.begin(),map_ev.end(),back_inserter(u_ev));
    sort(u_od.begin(),u_od.end(),[](auto& a, auto& b){ return a.second>b.second;});
    sort(u_ev.begin(),u_ev.end(),[](auto& a, auto& b){ return a.second>b.second;});
    ll ans=0;
    if(u_od[0].first==u_ev[0].first){
        ll t0=u_od[0].second;
        if(u_ev.size()>=1) t0+=u_ev[1].second;
        ll t1=u_ev[0].second;
        if(u_od.size()>=1) t1+=u_od[1].second;
        ans=max(t0,t1);
    } else {
        ans=u_od[0].second+u_ev[0].second;
    }
    cout<<n-ans<<endl;
    return 0;
}
