//AtCoder ABC104 A - Rated for Me
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    ll r; cin>>r;
    string ans;
    if (r<1200){
        ans="ABC";
    } else if(r<2800){
        ans="ARC";
    } else {
        ans="AGC";
    }
    cout<<ans<<endl;
    return 0;
}