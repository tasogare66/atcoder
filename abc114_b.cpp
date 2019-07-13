//AtCoder ABC114 B - 754
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    string S; cin>>S;
    ll ans=INT64_MAX;
    for(ll i=0;i<=(ll)S.size()-3;++i){
        ll v=std::stol(string(&S[i],3));
        ans=std::min<ll>(ans,abs((ll)753-v));
    }
    cout<<ans<<endl;
    return 0;
}