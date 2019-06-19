//AtCoder ABC073 B - Theater
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N;
    cin>>N;
    ll ans=0;
    for(ll i=0;i<N;++i){
        ll l,r;
        cin>>l>>r;
        ans+=(r-l+1);
    }
    cout<<ans<<endl;
    return 0;
}