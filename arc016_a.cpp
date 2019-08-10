//https://atcoder.jp/contests/arc016/tasks/arc016_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,M; cin>>N>>M;
    for(ll i=1;i<=N;++i){
        if(i!=M){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}