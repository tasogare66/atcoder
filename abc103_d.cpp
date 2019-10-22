//https://atcoder.jp/contests/abc103/tasks/abc103_d
//区間スケジューリング問題
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,M; cin>>N>>M;
    vector<pair<ll,ll>> bam(M); //b,a
    for(auto&& ba:bam){
        cin>>ba.second>>ba.first; //b,aでいれる
    }
    sort(bam.begin(),bam.end());
    ll ans=0;
    ll nowt=-1;
    REP(i,bam.size()){
        const auto& ba=bam.at(i);
        if(ba.second>=nowt){
            ++ans;
            nowt=ba.first;
        }
    }
    cout<<ans<<endl;
    return 0;
}