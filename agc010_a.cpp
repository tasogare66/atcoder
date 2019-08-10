//https://atcoder.jp/contests/agc010/tasks/agc010_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<ll> an(N);
    ll oddn=0;
    for(auto&& a:an){
        cin>>a;
        oddn += (a%2);
    }
    cout<<(oddn%2==0?"YES":"NO")<<endl;
    return 0;
}