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
        ll tmp= i%2019;
        if(modmin>tmp){ 
            modmin2=modmin;
            modmin=tmp;
            if(modmin==0)break;
        } else if (modmin2>tmp){
            modmin2=tmp;
        }
    }
    ll ans=modmin2*modmin;
    cout<<ans<<endl;
    return 0;
}