//https://atcoder.jp/contests/arc028/tasks/arc028_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,A,B; cin>>N>>A>>B;
    ll count=N/(A+B);
    ll r=N-(A+B)*count;
    cout<<(r!=0&&r-A<=0?"Ant":"Bug")<<endl;
    return 0;
}