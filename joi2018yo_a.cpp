//https://atcoder.jp/contests/joi2018yo/tasks/joi2018_yo_a
//A - 鉛筆 (Pencils)
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,A,B,C,D; cin>>N>>A>>B>>C>>D;
    ll x = ((N+A-1)/A)*B;
    ll y = ((N+C-1)/C)*D;    
    cout<<min(x,y)<<endl;
    return 0;
}