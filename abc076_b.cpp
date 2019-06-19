//AtCoder ABC076 B - Addition and Multiplication
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N,K;
    cin>>N>>K;
    ll ans=1;
    for(ll i=0;i<N;++i){
        ans=min(ans*2,ans+K);
    }    
    cout<<ans<<endl;
    return 0;
}