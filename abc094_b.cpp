//AtCoder ABC094 B - Toll Gates
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,M,X;cin>>N>>M>>X;
    unordered_map<ll,ll> amt;
    for(ll i=1;i<=M;++i){
        ll a;
        cin>>a;
        amt[a]++;
    }    
    //0に行く場合
    ll pt=X;
    ll ans0=0;
    while(pt>=0){
        --pt;
        auto itr = amt.find(pt);
        if(itr!=amt.end()) ++ans0;
    }
    //Nに行く場合
    pt = X;
    ll ans1=0;
    while(pt<=N){
        ++pt;
        auto itr = amt.find(pt);
        if(itr!=amt.end()) ++ans1;
    }
    //cout<<ans0<<","<<ans1<<endl;
    cout<<min(ans0,ans1)<<endl;
    return 0;
}