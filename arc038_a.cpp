//https://atcoder.jp/contests/arc038/tasks/arc038_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    sort(an.begin(),an.end(),greater<ll>());
    ll ans=0;
    REP(i,an.size()){
        if(i%2==0){
            ans+=an[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}