//AtCoder ABC102 A - Multiple of 2 and N
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
ll lcm(ll num1,ll num2){
    return num1 / __gcd(num1,num2) * num2; //gcc拡張
}
int main() {
    ll N; cin>>N;
    ll ans=lcm(2,N);
    cout<<ans<<endl;
    return 0;
}