//https://atcoder.jp/contests/arc053/tasks/arc053_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll H,W; cin>>H>>W;
    ll yoko=max(W-1,(ll)0)*H;
    ll tate=max(H-1,(ll)0)*W;
    cout<<yoko+tate<<endl;
    return 0;
}