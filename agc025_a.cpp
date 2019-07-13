//AtCoder AGC025 A - Digits Sum
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    ll ans=0;
    while(N>0){
        if(N==10){
            ans += N;
            break;
        }
        ll keta=N%10;
        N/=10;
        ans+=keta;
    }
    cout<<ans<<endl;
    return 0;
}