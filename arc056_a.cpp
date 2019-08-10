//https://atcoder.jp/contests/arc056/tasks/arc056_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll A,B,K,L; cin>>A>>B>>K>>L;
    auto calc = [&](ll b){
        ll a=max((ll)0,K-L*b);
        return a*A+B*b;
    };
    ll ans1=calc(K/L);
    ll ans2=calc((K+L-1)/L);
    cout<<min(ans1,ans2)<<endl;
    return 0;
}