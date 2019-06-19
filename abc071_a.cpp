//AtCoder ABC071 A - Meal Delivery
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll x,a,b;
    cin>>x>>a>>b;
    auto la=abs(x-a);
    auto lb=abs(x-b);
    cout<<(la<lb?"A":"B")<<endl;
    return 0;
}