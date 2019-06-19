//AtCoder ABC086 A - Product
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll a,b;
    cin>>a>>b;
    auto c=a*b;
    cout<<(c%2==1?"Odd":"Even")<<endl;
    return 0;
}