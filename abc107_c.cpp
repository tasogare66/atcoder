//AtCoder ABC107 C - Candles
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,K; cin>>N>>K;
    vector<ll> xn(N);
    vector<ll> lx,rx;
    bool zero_flag=false;
    for(auto& x:xn){
        cin>>x;
        if(x==0)zero_flag=true;
        else if(x>0) rx.push_back(abs(x));
        else if(x<0) lx.push_back(abs(x));
    }
    rx.push_back(0);
    lx.push_back(0);
    sort(rx.begin(),rx.end());
    sort(lx.begin(),lx.end());
    ll ans=INT64_MAX;
    if (zero_flag) --K;
    for(ll r=0;r<=K;++r){
        ll l=K-r;
        if(r >= rx.size()) continue;
        if(l >= lx.size()) continue;
        ll cur=2*min(rx[r],lx[l])+max(rx[r],lx[l]);
        ans=min(cur,ans);
    }
    cout<<ans<<endl;
    return 0;
}