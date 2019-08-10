//https://atcoder.jp/contests/arc036/tasks/arc036_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N, K; cin>>N>>K; 
    vector<ll> tn(N+1,0);
    FOR(i,1,N+1){
        cin>>tn[i];
    }
    ll k=0;
    ll ans=-1;
    for(ll i=1;i<=N;++i){
        k+=tn[i];
        if(i-3>=0) k-=tn[i-3];
        if(K>k&&i>2){
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}