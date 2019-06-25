//AtCoder ABC098 A - Add Sub Mul
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll A,B; cin>>A>>B;
    ll ans=max(A+B,A-B);
    ans=max(ans,A*B);
    cout<<ans<<endl;
    return 0;
}