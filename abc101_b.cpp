//AtCoder ABC101 B - Digit Sums
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N; cin>>N;
    ll s=0;
    ll n=N;
    while(n>0){
        s+=n%10;
        n/=10;
    }
    cout<<(N%s==0?"Yes":"No")<<endl;
    return 0;
}