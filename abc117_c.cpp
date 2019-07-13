//AtCoder ABC117 C - Streamline
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,M; cin>>N>>M;
    vector<ll> xm(M);
    for(auto&& x:xm){
        cin>>x;
    }
    sort(xm.begin(),xm.end());
    vector<ll> dist(M-1);
    for(ll i=0;i<xm.size()-1;++i){
        dist[i]=xm[i+1]-xm[i];
    }
    sort(dist.begin(),dist.end(),greater<ll>());
    ll ans=0;
    for(ll i=N-1;i<dist.size();++i){
        ans+=dist[i];
    }
    cout<<ans<<endl;
    return 0;
}