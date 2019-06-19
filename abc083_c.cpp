//AtCoder ABC083 C - Multiple Gift
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    uint64_t X,Y;
    cin>>X>>Y;
    auto v=X;
    ll ans=0;
    while(v<=Y){
        v*=2;
        ++ans;
    }
    cout<<ans<<endl;
    return 0;
}