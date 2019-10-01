//https://atcoder.jp/contests/abc072/tasks/arc082_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<ll> pn(N+1);
    FOR(i,1,N+1){
        cin>>pn.at(i);
    }
    ll ans=0;
    FOR(i,1,N){
        if(pn.at(i) == i) {
            swap(pn.at(i),pn.at(i+1));
            ++ans;
        }
    }
    //last
    if (pn.at(N) == N) ++ans;
    cout<<ans<<endl;
    return 0;
}
