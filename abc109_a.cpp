//AtCoder ABC109 A - ABC333
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    ll A,B; cin>>A>>B;
    ll ans=A*B;
    cout<<(ans%2==0?"No":"Yes")<<endl;
    return 0;
}