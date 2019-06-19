//AtCoder ABC067 C - Splitting Pile
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
    vector<ll> an(N+1,0);
    for(ll i=1;i<=N;++i){
        cin>>an[i];
    }
    ll sum=0;
    vector<ll> acc(N+1,0);
    for(ll i=1;i<=N;++i){
        sum+=an[i];
        acc[i]=sum;
    }
    ll ans=INT64_MAX;
    for(ll i=1;i<N;++i){
        ll x=acc[i];
        ll y=acc[N]-acc[i];
        ans = min(abs(x-y),ans);
    }
    cout<<ans<<endl;
    return 0;
}