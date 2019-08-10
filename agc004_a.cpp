//https://atcoder.jp/contests/agc004/tasks/agc004_a
//A - Divide a Cuboid
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll A,B,C; cin>>A>>B>>C;
    auto calc=[](ll x,ll y, ll z){
        return (x*y*z);
    };
    ll ans=INT64_MAX;
    //A
    ll a=A/2;
    ll aa=A-a;
    ans=min(abs(calc(a,B,C) - calc(aa,B,C)),ans);
    //B
    ll b=B/2;
    ll bb=B-b;
    ans=min(abs(calc(A,b,C) - calc(A,bb,C)),ans);
    //C
    ll c=C/2;
    ll cc=C-c;
    ans=min(abs(calc(A,B,c) - calc(A,B,cc)),ans);
    cout<<ans<<endl;
    return 0;
}