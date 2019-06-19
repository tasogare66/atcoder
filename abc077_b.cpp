//AtCoder ABC077 B - Around Square
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N;
    cin>>N;
    ll ans=0;
    for (ll i=1;i*i<=N;++i) {
        ans=max(ans,i*i);
    }
    cout<<ans<<endl;
    return 0;
}