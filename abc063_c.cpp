//AtCoder ABC063 C - Bugged
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N;
    cin>>N;
    vector<ll> stbl(N);
    ll ans=0;
    for(auto&& s:stbl){
        cin>>s;
        ans+=s;
    }
    sort(stbl.begin(),stbl.end());
    if (ans % 10==0){
        ll ans2=ans;
        for(const auto& s:stbl){
            if(s%10!=0){
                ans2-=s;
                break;
            }
        }
        ans=(ans==ans2?0:ans2);
    }
    cout<<ans<<endl;
    return 0;
}