//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll a,b; cin>>a>>b;
    ll dif=b-a;
    ll ans=0;
    for(ll i=1;i<=dif;++i){
        ans+=i;
    }
    ans=ans-b;
    cout<<ans<<endl;
    return 0;
}