//https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_a
//A - 合計時間 (Total Time)
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    vector<ll> tbl(4); 
    for(auto&& t:tbl){
        cin>>t;
    }   
    ll sec=accumulate(tbl.begin(),tbl.end(),0);
    ll x=sec/60;
    ll y=sec-x*60;
    cout<<x<<endl;
    cout<<y<<endl;
    return 0;
}