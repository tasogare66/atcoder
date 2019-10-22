//https://atcoder.jp/contests/joi2010yo/tasks/joi2010yo_b
//B - すごろく
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,M; cin>>N>>M; //Nます, M回    
    vector<ll> mas(N);
    for(auto&& m:mas){
        cin>>m;
    }
    vector<ll> sai(M);
    for(auto&& s:sai){
        cin>>s;
    }

    ll pt=0;
    ll ans=0;
    for(const auto& s:sai){
        ++ans;
        pt += s;
        if (pt<mas.size()) pt += mas.at(pt);
        if (pt>=mas.size()-1) break;
    }
    cout<<ans<<endl;
    return 0;
}