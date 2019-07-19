//https://atcoder.jp/contests/agc017/tasks/agc017_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-4.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,P; cin>>N>>P;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }

    auto check = [&](ll flag){
        ll num=0;
        REP(i,N){
            if(flag&(1<<i)) num+=an[i];
        }
        return num%2;
    };
    ll max=1<<N;
    ll ans=0;
    REP(i,max){
        if(check(i)==P)++ans;
    }
    cout<<ans<<endl;
    return 0;
}