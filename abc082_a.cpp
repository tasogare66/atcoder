//AtCoder ABC082 A - Round Up the Mean
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    double a,b;
    cin>>a>>b;
    double x=(a+b)/2.0;
    cout<<(ll)(x+0.5)<<endl;
    return 0;
}