//AtCoder ABC052 A - Two Rectangles
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d; 
    lli ans0=a*b;
    lli ans1=c*d; 
    cout<<(ans0>ans1?ans0:ans1)<<endl;
    return 0;
}