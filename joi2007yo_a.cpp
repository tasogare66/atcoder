//https://atcoder.jp/contests/joi2007yo/tasks/joi2007yo_a
//A - 得点
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    vector<ll> at(4);
    vector<ll> bt(4);
    for(auto&& a:at){
        cin>>a;
    }
    for(auto&& b:bt){
        cin>>b;
    }
    ll A = accumulate(at.begin(),at.end(),0);
    ll B = accumulate(bt.begin(),bt.end(),0);
    cout<<max(A,B)<<endl;
    return 0;
}