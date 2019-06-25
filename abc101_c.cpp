//AtCoder ABC101 C - Minimization
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N,K; cin>>N>>K;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    sort(an.begin(),an.end());
    ll num=N;
    for(auto&& a:an){
        if(a==an[0])--num;
        else break;
    }
    ll ans=num/(K-1);
    if(num%(K-1)!=0)++ans;
    cout<<ans<<endl;
    return 0;
}