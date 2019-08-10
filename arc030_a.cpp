//https://atcoder.jp/contests/arc030/tasks/arc030_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll n,k; cin>>n>>k;
    ll num=n/2;
    cout<<(k<=num?"YES":"NO")<<endl;
    return 0;
}