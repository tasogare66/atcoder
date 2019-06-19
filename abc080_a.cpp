//AtCoder ABC080 A - Parking
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N,A,B;
    cin>>N>>A>>B;
    ll ans=min(N*A,B);
    cout<<ans<<endl;
    return 0;
}