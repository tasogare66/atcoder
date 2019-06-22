//AtCoder ABC092 A - Traveling Budget
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll A,B,C,D;
    cin>>A>>B>>C>>D;
    auto ans=min(A,B)+min(C,D);
    cout<<ans<<endl;
    return 0;
}