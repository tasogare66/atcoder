//AtCoder ABC098 C - Attention
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N;
    string S;
    cin>>N>>S;
    vector<ll> etbl(N+1,0);
    vector<ll> wtbl(N+1,0);
    ll e=0;
    ll w=0;
    for(ll i=1;i<=N;++i){
        if(S[i-1]=='E') ++e;
        else ++w;
        etbl[i]=e;
        wtbl[i]=w;
    }
    ll ans=INT64_MAX;
    for(ll i=1;i<=N;++i){
        ll num=wtbl[i-1]+etbl[N]-etbl[i];
        ans=min(num,ans);
    }
    cout<<ans<<endl;
    return 0;
}