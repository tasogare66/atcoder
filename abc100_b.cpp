//AtCoder ABC100 B - Ringo's Favorite Numbers
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll D,N; cin>>D>>N;
    ll v=1;
    while(D>0){
        v*=100;
        --D;
    }
    if(N==100)++N; //100だと次へ
    ll ans=v*N;
    cout<<ans<<endl;
    return 0;
}