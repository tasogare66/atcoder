//https://atcoder.jp/contests/arc046/tasks/arc046_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    ll n=(N-1)/9;
    ll r=N%9;
    if(r==0)r=9;
    for(ll i=0;i<=n;++i){
        cout<<r;
    }
    cout<<endl;
    return 0;
}