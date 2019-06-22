//AtCoder ABC092 C - Traveling Plan
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N;
    cin>>N;
    vector<ll> an(N+2,0);
    ll ttl=0;
    for(ll i=1;i<=N;++i){
        cin>>an[i];
        ttl += abs(an[i-1]-an[i]);
    }
    ttl += abs(an[N]-0);
    vector<ll> ans(N+1,0);
    for(ll i=1;i<=N;++i){
        ans[i]=ttl-abs(an[i-1]-an[i])-abs(an[i]-an[i+1])+abs(an[i-1]-an[i+1]);
    }
    for(ll i=1;i<=N;++i){
        cout<<ans[i]<<endl;
    }
    return 0;
}