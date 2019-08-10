//https://atcoder.jp/contests/agc001/tasks/agc001_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<ll> l2n(2*N);
    for(auto&& l:l2n){
        cin>>l;
    }
    sort(l2n.begin(),l2n.end());
    ll ans=0;
    for(ll i=0;i<l2n.size();i+=2){
        ans+=min(l2n[i],l2n[i+1]);
    }
    cout<<ans<<endl;
    return 0;
}