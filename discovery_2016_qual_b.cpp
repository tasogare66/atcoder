//https://atcoder.jp/contests/discovery2016-qual/tasks/discovery_2016_qual_b
//B - ディスコ社内ツアー
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
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    //std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    map<ll,vector<ll>> tbl;
    REP(i,an.size()){
        ll a=an.at(i);
        tbl[a].push_back(i);
    }

    ll cur=0;
    ll ans=0;
    for(const auto& t:tbl){ //へやの順番に
        const auto& lst=t.second;
        assert(lst.size()>0);
        if(cur>lst.at(0)){
            auto it = lower_bound(lst.begin(),lst.end(),cur);
            auto index = distance(lst.begin(),it);
            assert(index>=1);
            cur=lst.at(index-1);
            ++ans;
        } else{
            cur=lst.back(); //終端
        }
    }
    if(cur!=0)++ans;
    cout<<ans<<endl;

    return 0;
}