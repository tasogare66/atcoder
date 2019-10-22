//https://atcoder.jp/contests/joi2015yo/tasks/joi2015yo_b
//B - クリスマスパーティー (Christmas Party)
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N; //人数
    ll M; cin>>M; //回数
    vector<ll> tgt(M); //ターゲット
    for(auto&& t:tgt){
        cin>>t;
    }
    vector<vector<ll>> kis(M,vector<ll>(N));
    for(auto&& ki:kis){
        for(auto&& t:ki){
            cin>>t;
        }
    }

    vector<ll> ans(N+1);
    REP(m,M){
        const auto& ki=kis.at(m);
        const auto target = tgt.at(m);
        ll X=0;
        REP(p,ki.size()){
            auto t = ki.at(p);
            if (t==target) {
                ++ans.at(p+1);
            }else{
                ++X;
            }
        }
        ans.at(target) += X;
    }

    FOR(i,1,N+1){
        cout<<ans.at(i)<<endl;
    }


    return 0;
}