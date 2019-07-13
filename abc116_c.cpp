//AtCoder ABC116 C - Grand Garden
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    vector<ll> hn(N+1,0);
    ll lowest=-1;
    ll hid=0;
    for(ll i=1;i<=N;++i){
        ll h; cin>>h;
        hn[i]=h;
        if(lowest<h){
            lowest=h;
            hid=i;
        }
    }
    ll ans=0;
    for(ll i=2;i<=hid;++i){
        ans += max<ll>(hn[i-1]-hn[i],0);
    }
    for(ll i=N-1;i>=hid;--i){
        ans += max<ll>(hn[i+1]-hn[i],0);
    }
    cout<<ans+lowest<<endl;
    return 0;
}
