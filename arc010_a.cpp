//https://atcoder.jp/contests/arc010/tasks/arc010_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,M,A,B; cin>>N>>M>>A>>B;
    vector<ll> cm(M+1);
    FOR(i,1,M+1){
        cin>>cm[i];
    }
    ll ans=-1;
    FOR(d,1,M+1){
        if(N<=A){
            N+=B;
        }
        N-=cm[d];
        if(N<0) {
            ans=d;
            break;
        }
    }
    if (ans<0){
        cout<<"complete"<<endl;
    } else {
        cout<<ans<<endl;
    }
    return 0;
}