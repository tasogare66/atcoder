//AtCoder ABC066 A - ringring
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    vector<ll> t(3,0);
    cin>>t[0]>>t[1]>>t[2];
    sort(t.begin(),t.end());
    cout<<t[0]+t[1]<<endl;
    return 0;
}