//AtCoder ABC095 B - Bitter Alchemy
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,X; cin>>N>>X;
    vector<ll> mn(N);
    ll ttl=0;
    ll minm=INT32_MAX;
    for(auto& m:mn){
        cin>>m;
        minm=min(m,minm);
        ttl+=m;
    }
    X-=ttl;
    ll ans=N;
    ans += X/minm;
    cout<<ans<<endl;
    return 0;
}