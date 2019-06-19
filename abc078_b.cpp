//AtCoder ABC078 B - ISU
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll x,y,z;
    cin>>x>>y>>z;
    auto len = x-z;
    cout<<len/(y+z)<<endl;
    return 0;
}