//https://atcoder.jp/contests/joi2015yo/tasks/joi2015yo_a
//A - 水道料金 (Water Rate)
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll A,B,C,D,P; cin>>A>>B>>C>>D>>P;
    ll vx = A*P;
    ll vy = B+max<ll>((P-C),0)*D;
    cout<<min(vx,vy)<<endl;
    return 0;
}