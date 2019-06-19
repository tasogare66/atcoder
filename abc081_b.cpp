//AtCoder B - Shift only
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N;
    cin>>N;
    vector<ll> atbl(N);
    for(auto&& a:atbl){
        cin>>a;
    }
    ll ans=0;
    bool okflag=true;
    while(okflag){
        for(auto&& a:atbl){
            if(a%2==0) a/=2;
            else {
                okflag=false;
                break;
            }
        }
        if(okflag)++ans;
    }
    cout<<ans<<endl;
    return 0;
}