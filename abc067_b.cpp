//AtCoder ABC067 B - Snake Toy
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N,K;
    cin>>N>>K;
    vector<ll> ltbl(N,0);
    for(auto&& l:ltbl){
        cin>>l;
    }
    sort(ltbl.begin(),ltbl.end(),greater<ll>());
    ll ans=0;
    for(int i=0;i<K;++i){
        ans+=ltbl[i];
    }
    cout<<ans<<endl;
    return 0;
}