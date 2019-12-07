//https://atcoder.jp/contests/ddcc2017-qual/tasks/ddcc2017_qual_c
//C - 収納
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
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,C; cin>>N>>C;
    vector<ll> ln(N);
    for(auto&& l:ln){
        cin>>l;
    }
    sort(ln.begin(),ln.end());

    ll ans=0;
    ll st=0,ed=ln.size()-1;
    while(st<=ed){
        auto st_l = ln.at(st);
        auto ed_l = ln.at(ed);
        if(st_l+ed_l+1<=C){
            ++st;
            --ed;
        }else{
            --ed;
        }
        ++ans;
    }
    cout<<ans<<endl;
    return 0;
}