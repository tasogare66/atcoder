//AtCoder ABC064 B - Traveling AtCoDeer Problem
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
    sort(atbl.begin(),atbl.end());
    ll ans=0;
    for(int i=1;i<atbl.size();++i){
        ans+=atbl[i]-atbl[i-1];
    }
    cout<<ans<<endl;
    return 0;
}