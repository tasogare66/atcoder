//https://atcoder.jp/contests/agc040/tasks/agc040_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
struct Info{
    ll l=0,r=0;
};

typedef pair<ll,ll> range;
#define low first
#define high second

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<range> lrn(N);
    for(auto&& lr:lrn){
        cin>>lr.first>>lr.second;
    }
    sort(lrn.begin(),lrn.end(),[](const auto& a, const auto &b){
        if (a.second==b.second) return a.first<b.first;
        return a.second>b.second;}); //FIXME:   
//        return a.first<b.first;});

    ll ans=0;
    vector<ll> atbl(N),btbl(N);
    ll llv=0,rrv=INT64_MAX;
    FOR(i,0,N){
        const auto& p=lrn.at(i);
        rrv=min(rrv,p.second);
        llv=max(llv,p.first);
        atbl.at(i)=max<ll>(rrv-llv+1,0);
    }
    llv=0,rrv=INT64_MAX;
    for(ll i=N-1;i>=0;--i){
        const auto& p=lrn.at(i);
        rrv=min(rrv,p.second);
        llv=max(llv,p.first);
        btbl.at(i)=max<ll>(rrv-llv+1,0);
    }
    REP(i,N-1){
        ans=max(atbl.at(i)+btbl.at(i+1),ans);
    }
    cout<<ans<<endl;
    return 0;
}