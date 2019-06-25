//AtCoder ABC094 C - Many Medians
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
struct Dat{
    ll x;
    ll base; //元のid
    ll cur; //sort済のid
};
int main() {
    ll N;cin>>N;
    vector<Dat> xn(N+1);
    for(ll i=1;i<=N;++i){
        auto&& d=xn[i];
        cin>>d.x;
        d.base=i;
    }
    sort(xn.begin(),xn.end(),[](const auto& a,const auto& b){
        return (a.x<b.x);
    });
    unordered_map<ll,ll> mp;
    for(ll i=1;i<=N;++i){
        auto&& d=xn[i];
        d.cur=i;
        mp[d.base]=i;
    }

    ll cent=(N-1+1)/2; //1つ数字をとるので
    auto ctdno = [&](ll d){
       if(d<cent){
           return cent+1;
       } else if(d==cent){
           return cent+1;
       } else {
           return cent;
       }
    };
    for(ll i=1;i<=N;++i){
        cout<<xn[ctdno(mp[i])].x<<endl;
    }
    return 0;
}