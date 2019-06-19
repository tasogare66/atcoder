//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N;
    cin>>N;
    vector<pair<ll,ll>> tbl(N);
    for(auto&& t:tbl){
        cin>>t.first>>t.second;
    }
    map<pair<ll,ll>,ll> count;
    for(ll i=0;i<N;++i){
        for(ll j=0;j<N;++j){
            if (i==j) continue;
            ll dx=tbl[i].first - tbl[j].first;
            ll dy=tbl[i].second - tbl[j].second;
            count[make_pair(dx,dy)]++;
        }
    }
    pair<ll,ll> now; //選んだやつ
    ll max=0;
    for(auto&& c:count){
        if(max<c.second){
            now=c.first;
            max=c.second;
        }
    }
    //探索
    // ll num=0;
    // for(ll i=0;i<N;++i){
    //     auto nx=tbl[i].first + now.first;
    //     auto ny=tbl[i].second + now.second;
    //     auto it = std::find(tbl.begin(),tbl.end(),make_pair(nx,ny));
    //     if (it!=tbl.end()){
    //         ++num;
    //     }
    // }
    ll ans=tbl.size()-max;
    cout<<ans<<endl;
    return 0;
}