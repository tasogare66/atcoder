//https://atcoder.jp/contests/abc135/tasks/abc135_c
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
    ll N; cin>>N;
    vector<ll> an(N+2);
    FOR(i,1,N+2){
        cin>>an[i];
    }
    vector<ll> bn(N+1);
    FOR(i,1,N+1){
        cin>>bn[i];
    }
    ll ans=0;
    for(ll i=1;i<=N;++i){
        ll a=an[i]+an[i+1];
        ll b=bn[i];
        ans += min(a,b);
        an[i+1]-=max(b-an[i],(ll)0);
        an[i+1]=max(an[i+1],(ll)0);
    }
    cout<<ans<<endl;
    return 0;
}