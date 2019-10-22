//https://atcoder.jp/contests/joi2007yo/tasks/joi2007yo_b
//B - 未提出者は誰だ
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    vector<ll> flag(30+1,false);    
    REP(i,28){
        ll n; cin>>n;
        flag.at(n)=true;
    }
    FOR(i,1,31){
        if(!flag.at(i)) cout<<i<<endl;
    }
    return 0;
}