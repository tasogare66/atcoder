//AtCoder ABC110 A - Maximize the Formula
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    vector<ll> t(3);
    cin>>t[0]>>t[1]>>t[2];
    sort(t.begin(),t.end());
    ll ans=t[2]*10+t[1]+t[0];
    cout<<ans<<endl;
    return 0;
}
