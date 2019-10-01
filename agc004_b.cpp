//https://atcoder.jp/contests/agc004/tasks/agc004_b
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
    ll N,x; cin>>N>>x;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    
    ll ans=INT64_MAX;
    vector<ll> mincst(N, INT64_MAX);
    REP(t,N){ //移動回数で全探索
        ll sum=t*x; //移動cost
        REP(i,N){
            ll idx = i-t<0 ? i-t+N : i-t;
            mincst.at(i) = min(mincst.at(i), an.at(idx));
            sum += mincst.at(i);
        }
        ans = min(ans,sum);
    }
    cout<<ans<<endl;

    return 0;
}