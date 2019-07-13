//AtCoder ABC121 C - Energy Drink Collector
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,M; cin>>N>>M;
    vector<pair<ll,ll>> abn(N);
    for(auto&& ab:abn){
        cin>>ab.first>>ab.second;
    }
    sort(abn.begin(),abn.end());
    ll ans=0;
    for(const auto& ab:abn){
        if(M<=0) break;
        ans+=min(M,ab.second)*ab.first;
        M-=ab.second;
    }
    cout<<ans<<endl;
    return 0;
}