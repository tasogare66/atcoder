//https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_a
//A - ランチ (Lunch)
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    vector<ll> past(3);
    vector<ll> jyu(2);
    for(auto&& y:past){
        cin>>y;
    }
    for(auto&& y:jyu){
        cin>>y;
    }
    sort(past.begin(),past.end());
    sort(jyu.begin(),jyu.end());
    ll ans=past.at(0)+jyu.at(0)-50;
    cout<<ans<<endl;
    return 0;
}