//https://atcoder.jp/contests/abc138/tasks/abc138_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll a; string s; cin>>a>>s;
    if (a>=3200) {
        cout<<s<<endl;
    } else {
        cout<<"red"<<endl;
    }
    return 0;
}