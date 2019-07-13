//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    ll ans=20000;
    ll a,b;
    for(ll i=100;i<=200;++i){
        for(ll j=100;j<=200;++j){
            if(i<j) {
                ll tmp= i*j%2019;
                cout<<i<<","<<j<<","<<tmp<<endl;
                if (tmp==1){ a=i;b=j;}
                ans=min((i*j)%2019,ans);
            }
        }
    }
    cout<<ans<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}