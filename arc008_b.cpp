//https://atcoder.jp/contests/arc008/tasks/arc008_2
//B - 謎のたこ焼きおじさん
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
    ll N,M; cin>>N>>M;
    string name, kit; cin>>name>>kit;
    unordered_map<char,ll> name_m, kit_m;
    for(auto c:name){
        name_m[c]++;
    }
    for(auto c:kit){
        kit_m[c]++;
    }
    ll ans=0;
    for(auto& p:name_m){
        auto req = p.second;
        auto kit_num= kit_m[p.first];
        if (kit_num==0){
            ans=-1;
            break;
        }
        ll set_num = (req + kit_num -1)/ kit_num;
        ans = max(ans, set_num);
    }
    cout<<ans<<endl;
    return 0;
}