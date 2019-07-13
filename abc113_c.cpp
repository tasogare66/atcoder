//AtCoder ABC113 C - ID
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
struct Dat {
    ll p; //県no
    ll y; //年
    ostringstream ss;
    void make_id(ll no){
        ss << std::setw(6) << std::setfill('0') << p;
        ss << std::setw(6) << std::setfill('0') << no;
    }
};
int main() {
    ll N,M; cin>>N>>M;
    vector<Dat> pym(M);;
    for(auto && py:pym){
        cin>>py.p>>py.y;
    }
    unordered_map<ll,vector<ll>> kentbl; //p県,市のindex
    for(ll i=0;i<pym.size();++i){
        ll pno=pym[i].p;
        kentbl[pno].push_back(i);
    }
    for(auto&& m:kentbl){
        auto& vec=m.second;
        sort(vec.begin(),vec.end(), [&](const auto&a,const auto&b){
            return (pym[a].y < pym[b].y);
        });
        //idつくる
        for(ll i=0;i<vec.size();++i){
            ll no=i+1;
            pym[vec[i]].make_id(no);
        }
    }
    //output
    for(auto && py:pym){
        cout<<py.ss.str()<<endl;
    }
    return 0;
}