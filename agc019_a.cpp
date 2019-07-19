//https://atcoder.jp/contests/agc019/tasks/agc019_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
struct Dat{
    ll cost;
    ll vol;
    ll cost_per_vol=0; //2l(200)の値段
    Dat(ll icos,ll ivol)
        : cost(icos), vol(ivol) 
    {
        cost_per_vol = cost * (200/ivol);
    }
};
int main() {
    ll Q,H,S,D; cin>>Q>>H>>S>>D;
    ll N; cin>>N; N*=100; //1l->100にする
    vector<Dat> tbl;
    tbl.push_back(Dat(Q,25));
    tbl.push_back(Dat(H,50));
    tbl.push_back(Dat(S,100));
    tbl.push_back(Dat(D,200));
    sort(tbl.begin(),tbl.end(),[](const auto& a, const auto&b){ return a.cost_per_vol < b.cost_per_vol; });
    ll ans=0;
    for(const auto& d:tbl){
        ll tmp=N/d.vol;
        ans+=tmp*d.cost;
        N-=tmp*d.vol;
    }
    cout<<ans<<endl;
    return 0;
}