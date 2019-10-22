//https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_b
//B - ポイントカード (Point Card)
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,M; cin>>N>>M; //2Nマス
    vector<pair<ll,ll>> card(M);
    for(auto&& c:card){
        cin>>c.first>>c.second;
    }
    sort(card.begin(),card.end(),[](auto& a,auto& b){return a.first>b.first;});
    ll ans=0;
    REP(i,M-1){
        const auto& c= card.at(i);
        ans += max<ll>(0,N-c.first);
    }
    cout<<ans<<endl;
    return 0;
}