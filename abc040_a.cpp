//AtCoder ABC040 A - 赤赤赤赤青
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int n,x;
    cin>>n>>x;
    int l=max(0,x-1); 
    int r=n-x;
    cout<<min(l,r)<<endl;
    return 0;
}