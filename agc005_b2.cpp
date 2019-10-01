//https://atcoder.jp/contests/agc005/tasks/agc005_b
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
    vector<ll> an(N+1);
    vector<ll> pos(N+1); //aの場所
    FOR(i,1,N+1){
        ll a; cin>>a;
        an.at(i) = a;
        pos.at(a) = i;
    }

    set<ll> tbl{0,N+1}; //小さい順
    // for(auto it=tbl.begin(); it != tbl.end();++it){
    //     cout<<*it<<endl;
    // }
    ll ans=0;
    FOR(v,1,N+1){ //小さい値から
        auto p = pos.at(v);
        auto it = tbl.lower_bound(p);
        auto r = *it;
        auto l = *(--it);
        ans += v * (r-p) * (p-l);

        tbl.insert(p);
    }
    cout<<ans<<endl;
    return 0;
}