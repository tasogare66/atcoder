//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll A,B;
    cin>>A>>B;
    ll ans=0;
    for(ll i=A;i<=B;++i){
        auto a=to_string(i);
        auto b=a;
        reverse(b.begin(),b.end());
        if (a==b) ++ans;
    }
    cout<<ans<<endl;
    return 0;
}