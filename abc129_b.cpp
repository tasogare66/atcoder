//AtCoder ABC129
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
    vector<ll> wn(N+1,0);
    ll sum=0;//total
    vector<ll> acc(N+1,0);
    for(ll i=1;i<=N;++i){
        cin>>wn[i];
        sum+=wn[i];
        acc[i]=sum;
    }
    ll ans=INT64_MAX;
    for(ll i=1;i<=N;++i){
        ll s1=acc[i];
        ll s2=sum-s1;
        ans=min(abs(s1-s2),ans);
    }
    cout<<ans<<endl;
    return 0;
}