//https://atcoder.jp/contests/joi2014yo/tasks/joi2014yo_a
//A - 平均点 (Average Score)
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    vector<ll> score(5); 
    for(auto& s:score){
        cin>>s;
        s=max<ll>(40,s);
    }   
    ll ans=accumulate(score.begin(),score.end(),0)/5;
    cout<<ans<<endl;
    return 0;
}