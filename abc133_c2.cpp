//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll l,r; cin>>l>>r;
    ll modmin=20000;
    ll modmin2=20000;
    for(ll i=l;i<=r;++i){
        if(i%2019==0) {
            cout<<0<<endl;
            return 0;
        }
    }
    ll ans=2000000;
    ll tl=l%2019;
    ll tr=r%2019;
    for(ll i=tl;i<=tr;++i){
        for(ll j=tl;j<=tr;++j){
            if(i<j) {
                ll tmp= i*j%2019;
                ans=min((i*j)%2019,ans);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}