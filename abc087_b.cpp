//AtCoder ABC087 B - Coins
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll A,B,C,X;
    cin>>A>>B>>C>>X;
    ll ans=0;
    for(ll i=0;i<=A;++i){
        for(ll j=0;j<=B;++j){
            for(ll k=0;k<=C;++k){
                if(i*500+j*100+k*50==X) ++ans;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}