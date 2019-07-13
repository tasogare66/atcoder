//AtCoder ABC132 C - Divide the Problems
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    ll N; cin>>N;
    vector<ll> dn(N);
    for(auto&& d:dn){
        cin>>d;
    }
    sort(dn.begin(),dn.end());
    ll n2=N/2;
    ll ans= dn[n2]-dn[n2-1];
    cout<<ans<<endl;
    return 0;
}