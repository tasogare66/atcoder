//AtCoder ABC120 A - Favorite Sound
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    ll A,B,C; cin>>A>>B>>C;
    ll ans=min(B/A,C);
    cout<<ans<<endl;
    return 0;
}