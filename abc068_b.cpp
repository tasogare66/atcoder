//AtCoder ABC068 B - Break Number
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N;
    cin>>N;
    ll ans=1;
    ll max_cnt=0;
    auto check_func = [](ll v){
        ll cnt=0;
        while(v%2==0&&v>1){
            v/=2;
            ++cnt;
        }
        return cnt;
    };
    for(ll i=1;i<=N;++i){
        ll cnt=check_func(i);
        if(cnt>max_cnt){
            max_cnt=cnt;
            ans=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}