//AtCoder ABC096 B - Maximum Sum
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll K;
    vector<ll> abc(3);
    cin>>abc[0]>>abc[1]>>abc[2];
    cin>>K;
    sort(abc.begin(),abc.end());
    ll ans=abc[2];
    for(ll i=0;i<K;++i){
        ans *= 2;
    }
    cout<<ans+abc[0]+abc[1]<<endl;
    return 0;
}