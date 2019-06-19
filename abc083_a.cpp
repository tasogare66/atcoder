//AtCoder ABC083 A - Libra
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<(a+b>c+d?"Left":a+b==c+d?"Balanced":"Right")<<endl;
    return 0;
}