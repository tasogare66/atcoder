//https://atcoder.jp/contests/joi2013yo/tasks/joi2013yo_a
//A - 宿題 (Homework)
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll L,A,B,C,D;
    cin>>L>>A>>B>>C>>D;
    ll d0=(A+(C-1))/C;
    ll d1=(B+(D-1))/D;
    cout<<L-max(d0,d1)<<endl;
    return 0;
}