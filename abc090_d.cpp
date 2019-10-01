//https://atcoder.jp/contests/abc090/tasks/arc091_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-3.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,K; cin>>N>>K;
    ll ans=0;
    FOR(b,K+1,N+1){
#if LOCAL
        cout<<"-"<<b<<endl;
#endif
        for(ll k=K;k<b;++k){
            ll add = (k!=0)+(N-k)/b;
            ans += add; //k==0は+1しない
#if LOCAL
            cout<<k<<","<<add<<endl;
#endif
        }
//        cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}