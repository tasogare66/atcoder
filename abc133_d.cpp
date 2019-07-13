//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    ll N; cin>>N;
    vector<ll> an(N+1,0);
    for(ll i=1;i<=N;++i){
        cin>>an[i];
    }
    ll sum=0;
    for(ll i=N;i>=1;--i){
        if(i%2==1){
            sum+=an[i];
        } else {
            sum-=an[i];
        }
    }
    ll ans=sum/2;
    cout<<ans*2;
    ll prev=ans;
    for(ll i=1;i<N;++i){
        prev =an[i]-prev;
        cout<<" "<<(prev)*2;
    }
    cout<<endl;
    return 0;
}