//AtCoder ABC056 C - Go Home
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&01
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    //n*(1+n)/2 = S
    //n^2+n+2S=0
    //解の公式(-1+sqrt(1+8S))/2
    ll X;
    cin>>X;
    double tmp=1+8*X;
    double dans = (sqrt(tmp)-1.0)/2.0;
    int ans=ceil(dans);
    cout<<ans<<endl;
    return 0;
}