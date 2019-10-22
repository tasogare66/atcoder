//https://atcoder.jp/contests/joi2013yo/tasks/joi2013yo_b
//B - 数当てゲーム (Unique Number)
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;    
    vector<vector<ll>> sc(3,vector<ll>(N));
    REP(i,N){
        cin>>sc[0][i]>>sc[1][i]>>sc[2][i];
    }
    vector<ll> ans(N,0);
    auto calc = [&](ll t){
        const auto& tbl = sc.at(t);
        REP(i,N){
            auto v = tbl.at(i);
            bool flag = true;
            REP(j,N){
                if (i!=j) {
                    flag &= (v!=tbl.at(j));
                }
            }
            if(flag) ans.at(i) += v;
        }
    };

    calc(0);
    calc(1);
    calc(2);

    for(const auto& v:ans){
        cout<<v<<endl;
    }

    return 0;
}