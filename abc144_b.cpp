//https://atcoder.jp/contests/abc144/tasks/abc144_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    FOR(i,1,9+1){
        FOR(j,1,9+1){
            if(i*j==N) {cout<<"Yes"<<endl;return 0;}
        }
    }
    cout<<"No"<<endl;
    return 0;
}