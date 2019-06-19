//AtCoder ABC081 C - Not so Diverse
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,K;
    cin>>N>>K;
    vector<ll> atbl(N);
    unordered_map<ll,ll> vnum;
    for(auto&& a:atbl){
        cin>>a;
        ++vnum[a];
    }
    vector<ll> sl(vnum.size());
    ll i=0;
    for(auto&& v:vnum){
        sl[i++]=v.first;
    }
    sort(sl.begin(),sl.end(),[&](auto& a,auto& b){
        return (vnum[a] < vnum[b]);
    });
    ll ans=0;
    for(ll i=0;i<((ll)vnum.size()-K);++i){
        ans+=vnum[sl[i]];
    }
    cout<<ans<<endl;
    return 0;
}