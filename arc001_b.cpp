//https://atcoder.jp/contests/arc001/tasks/arc001_2
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll A,B; cin>>A>>B;
    ll ans=0;
    auto updfunc=[&](){
        vector<ll> ofs = {
            10,-10,5,-5,1,-1
        };
        ll bst=INT64_MAX;
        ll a=A;
        for(const auto& d:ofs){
            ll diff=abs(A+d-B);
            if(bst>diff){
                bst=diff;
                a=A+d;
            }
        }
        return a;
    };
    while(A!=B){
        A=updfunc();
        ++ans;
    }
    cout<<ans<<endl;
    return 0;
}