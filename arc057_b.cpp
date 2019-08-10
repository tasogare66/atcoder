//https://atcoder.jp/contests/arc057/tasks/arc057_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,K; cin>>N>>K;    
    vector<ll> an(N+1,0);
    FOR(i,1,N+1){
        cin>>an[i];
    }
    vector<ll> sum(N+1);
    vector<double> per(N+1); //1であがる割合
    FOR(i,1,N+1){
        sum[i]=sum[i-1]+an[i];
    }
    return 0;
}