//AtCoder ABC097 B - Exponential
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

ll pw(ll a,ll b){
    ll ret=1;
    for(ll i=0;i<b;++i){
        ret*=a;
    }
    return ret;
}

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll X; cin>>X;
    ll ans=1;
    for(ll i=2;i<=sqrt(X);++i){
        ll tmp=X;
        ll cnt=0;
        while(tmp>=i){
            ++cnt;
            tmp/=i;
        }
        ans=max(pw(i,cnt),ans);
    }
    cout<<ans<<endl;    
    return 0;
}