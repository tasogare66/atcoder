//AtCoder ABC116 A - Right Triangle
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    vector<ll> e(3);
    cin>>e[0]>>e[1]>>e[2];
    sort(e.begin(),e.end());
    ll ans=e[0]*e[1]/2;
    cout<<ans<<endl;
    return 0;
}