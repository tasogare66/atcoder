//https://atcoder.jp/contests/abc140/tasks/abc140_c
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
//    cin.tie(0);
//    ios::sync_with_stdio(false);
    ll N; cin>>N;
    vector<ll> bn(N-1);
    vector<ll> an(N);
    for(auto&& b:bn){
        cin>>b;
    }

    an[0]=bn[0];
    FOR(i,1,N){
        an[i]=bn[i-1];
        an[i-1]=min(an[i-1],bn[i-1]);
    }
    ll ans = 0;
    for(const auto& a:an){
        ans+=a;
    }
    cout<<ans<<endl;
    return 0;
}