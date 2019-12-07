//https://atcoder.jp/contests/abc144/tasks/abc144_c
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
    ll N; cin>>N;
    ll rt=sqrt(N);    
    ll ans=INT64_MAX;
    FOR(i,1,rt+2){
        if(N%i==0){
            ll a=i;
            ll b=N/a;
            ans=min(a-1+b-1,ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}