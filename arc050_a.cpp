//https://atcoder.jp/contests/arc050/tasks/arc050_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    char C,c; cin>>C>>c;    
    ll u=C-'A';
    ll l=c-'a';
    cout<<(u==l?"Yes":"No")<<endl;
    return 0;
}