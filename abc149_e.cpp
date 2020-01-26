//https://atcoder.jp/contests/abc149/tasks/abc149_e
//E - Handshake
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
template<class T>bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1; } return 0;}
struct Info {
    ll sum=0;
    ll id0,id1;
};
#if 01
int main(){
#if LOCAL&0
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,M; cin>>N>>M;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    sort(an.begin(),an.end());
    dump(an);

    //M回の閾値
    auto check_func = [&](ll v)->bool{
        ll cnt=0;
        FOR(i,0,N){
            ll tmp = v-an.at(i);
            auto it = lower_bound(an.begin(), an.end(), tmp);
            cnt += distance(it, an.end()); 
        }
        return (cnt>=M);
    };

    ll lb=0,ub= INT64_MAX;
    while(ub-lb>1){
        ll mid=(ub+lb)/2;
        auto ck = check_func(mid);
        if (ck){
            lb=mid;
        }else{
            ub=mid;
        }
        //dump(mid,ck,lb,ub);
    }
    dump(lb);

    //累積和
    vector<ll> sums(N+1);
    FOR(i,0,N){
        sums[i+1] = sums[i] + an.at(i);
    }
    ll ans=0;
    ll m=M;
    FOR(i,0,N){
        auto r = an.end() - lower_bound(an.begin(), an.end(), lb-an.at(i));
        m -= r;
        auto ad=sums[N] - sums[N-r] + an.at(i)*r;
        dump(i, r,ad);
        ans += ad;
    }
    dump(m,ans);
    ans += lb * m;
    cout<<ans<<endl;
    return 0;
}
#else
int main() {
    ll N,M; cin>>N>>M;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    sort(an.begin(),an.end(),greater<ll>());
    dump(an);      

    vector<Info> tbl;
    tbl.reserve(N*N);
    REP(i,N){
        REP(j,N){
            Info info;
            info.sum=an[i]+an[j];
            info.id0=i;
            info.id1=j;
            tbl.push_back(move(info));
        }
    }
    sort(tbl.begin(),tbl.end(),[](const auto& a,const auto& b){ return a.sum>b.sum;});
    ll ans=0;
    REP(i,M){
        const auto& d=tbl[i];
        ans += d.sum;
        dump(d.id0,d.id1,d.sum);
    }
    cout<<ans<<endl;

    return 0;
}
#endif