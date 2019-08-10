//https://atcoder.jp/contests/arc024/tasks/arc024_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll L,R; cin>>L>>R;
    vector<ll> llt(L);
    vector<ll> rrt(R);
    for(auto&&l :llt){
        cin>>l;
    }
    sort(llt.begin(),llt.end());
    for(auto&&r :rrt){
        cin>>r;
    }
    sort(rrt.begin(),rrt.end());
    ll ans=0;
    ll rst=0;
    for(ll l=0;l<llt.size();++l){
        for(ll r=rst;r<rrt.size();++r){
            if(llt[l]==rrt[r]){
                ++ans;
                rst=r+1;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}