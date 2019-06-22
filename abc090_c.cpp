//AtCoder ABC090 C - Flip,Flip, and Flip......
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N,M;
    cin>>N>>M;
    ll ans=0;
    if(N==1&&M==1){
        ans=1;
    }else if(N==1){
        ans=max<ll>(M-2,0);
    }else if(M==1){
        ans=max<ll>(N-2,0);
    }else{
        ans=(N-2)*(M-2);
    }
    cout<<ans<<endl;
    return 0;
}