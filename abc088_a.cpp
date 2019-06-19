//AtCoder ABC088 A - Infinite Coins
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N,A;
    cin>>N>>A;
    ll r=N%500;
    cout<<(r<=A?"Yes":"No")<<endl;
    return 0;
}