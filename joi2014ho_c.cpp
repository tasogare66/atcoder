//https://atcoder.jp/contests/joi2014ho/tasks/joi2014ho3
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N; //切り込み数    
    vector<ll> an(N);
    ll sum=0;
    for(auto&& a:an){
        cin>>a;
        sum += a;
    }

    auto check_func = [&](ll my){ //取れる?
        array<ll,3> b{0,0,0};
        ll idx=0;
        FOR(i,0,an.size()){
            b.at(idx) += an.at(i);
        }
        return true;
    };

    ll lb=0,ub=sum+1;
    while(ub-lb>1){
        ll mid=(ub+lb)/2;
        if (check_func(mid)){
            lb=mid;
        }else{
            ub=mid;
        }
    }
    cout<<lb<<endl;

    return 0;
}