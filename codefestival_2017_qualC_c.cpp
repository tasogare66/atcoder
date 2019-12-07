//https://atcoder.jp/contests/code-festival-2017-qualc/tasks/code_festival_2017_qualc_c
//C - Inserting 'x'
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
    string s; cin>>s;
    string s_delx;
    for(const auto& c:s){
        if(c!='x') s_delx.push_back(c);
    }
    string s_rev=s_delx;
    reverse(s_rev.begin(),s_rev.end());
    if(s_rev!=s_delx) {cout<<-1<<endl; return 0;} //無理
    ll l=0,r=s.size()-1;
    ll ans=0;
    while(l<r){
        if(s.at(l)!=s.at(r)){
            if(s.at(l)!='x'){
                ++ans;
                --r;
            } else if(s.at(r)!='x'){
                ++ans;
                ++l;
            }else{
                assert(0);
            }
        }else{
            ++l;
            --r;
        }
    }
    cout<<ans<<endl;
    return 0;
}