//AtCoder ABC113 B - Palace
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    ll N; cin>>N;
    ll T,A; cin>>T>>A;
    vector<ll> hn(N);
    for(auto&& h:hn){
        cin>>h;
    }
    double tmin=1e6;
    ll idx=-1;
    for(ll i=0;i<hn.size();++i){
        double t=A-(T-hn[i]*0.006);
        t=abs(t);
        if(tmin>t){
            idx=i;
            tmin=t;
        }
    }
    cout<<idx+1<<endl;
    return 0;
}