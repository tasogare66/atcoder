//AtCoder ABC130 B - Bounding	
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N,X;
    cin>>N>>X;
    vector<ll> ltbl(N);
    for(auto&& l:ltbl){
        cin>>l;
    }
    ll d=0;
    ll ans=0;
    for(int i=0;i<N;++i){
        d=d+ltbl[i];
        if(d<=X){
            ++ans;
        }
    }
    cout<<ans+1<<endl;
    return 0;
}