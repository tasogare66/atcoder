//AtCoder ABC048 C - Boxes and Candies
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    lli N,x;
    cin>>N>>x;
    vector<lli> atbl(N);
    for(auto&& a:atbl){
        cin>>a;
    }
    lli ans=0;
    for(lli i=1;i<N;++i){
        lli diff=max(atbl[i]+atbl[i-1]-x,(lli)0);
        auto r = min(atbl[i],diff);
        diff -= r;
        auto l = min(atbl[i-1],diff);
        ans += (l+r);
        atbl[i] -= r;
        atbl[i-1] -= l;
    }
    cout<<ans<<endl;
    return 0;
}