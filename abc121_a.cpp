//AtCoder ABC121 A - White Cells
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll H,W; cin>>H>>W;
    ll h,w; cin>>h>>w;
    ll ans=H*W - h*W - w*H +h*w;
    cout<<ans<<endl;
    return 0;
}