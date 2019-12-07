//https://atcoder.jp/contests/agc024/tasks/agc024_b
//B - Backfront
//LIS? longest_inceasing_subsequence
//->連続する部分列以外は移動させないといけないので、連続する部分列の数を調べる
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<pair<ll,ll>> pn(N+1); //P,場所i
    FOR(i,1,N+1){
        auto&& p=pn.at(i);
        cin>>p.first;
        p.second=i;
    }
    sort(pn.begin(),pn.end());
    dump(pn);
    ll cnt=1;
    ll ans=1;
    FOR(i,2,N+1){
        const auto& prev=pn.at(i-1);
        const auto& cur=pn.at(i);
        if(cur.second>prev.second){
            ++cnt;
            ans=max(ans,cnt);
        }else {
            cnt=1;
        }
    }
    cout<<N-ans<<endl;

    return 0;
}