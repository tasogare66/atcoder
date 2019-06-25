//AtCoder ABC097 A - Colorful Transceivers
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    bool ans= abs(a-c)<=d||(abs(a-b)<=d&&abs(b-c)<=d);
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}