//AtCoder ABC111 B - AtCoder Beginner Contest 111
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    ll N; cin>>N;
    vector<ll> tbl={
        111,222,333,444,555,666,777,888,999,
    };
    ll ans=111;
    for(ll i=1;i<tbl.size();++i){
        if(tbl[i-1]<N&&N<=tbl[i]) {
            ans= tbl[i];
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}