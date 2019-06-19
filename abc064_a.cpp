//AtCoder ABC054 A - RGB Cards
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll r,g,b;
    cin>>r>>g>>b;
    ll ans=r*100+g*10+b;
    cout<<(ans%4==0?"YES":"NO")<<endl;
    return 0;
}