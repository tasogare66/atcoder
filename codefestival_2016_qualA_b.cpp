//https://atcoder.jp/contests/code-festival-2016-quala/tasks/codefestival_2016_qualA_b
//B - 仲良しうさぎ / Friendly Rabbits
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<ll> an(N+1,0);
    FOR(i,1,N+1){
        cin>>an.at(i);
    }
    ll ans=0;
    FOR(i,1,N+1){
        ll a=an.at(i);
        if(an.at(a)==i) ++ans;
    }
    ans/=2;
    cout<<ans<<endl;
    return 0;
}