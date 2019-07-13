//AtCoder ABC112 B - Time Limit Exceeded
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    ll N,T; cin>>N>>T;
    vector<pair<ll,ll>> ctn(N);
    for(auto&& ct:ctn){
        cin>>ct.first>>ct.second;
    }
    ll ans=INT64_MAX;
    for(const auto& ct:ctn){
        if(ct.second<=T) {
            ans=min(ans,ct.first);
        }
    }
    if(ans>=INT64_MAX){
        cout<<"TLE"<<endl;
    }else{
        cout<<ans<<endl;
    }
    return 0;
}
