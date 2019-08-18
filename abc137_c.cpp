//https://atcoder.jp/contests/abc137/tasks/abc137_c
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    set<string> tbl;
    unordered_map<string,ll> cnt;
    REP(i,N){
        string s; cin>>s;
        sort(s.begin(),s.end());
        ++cnt[s];
    }
    ll ans=0;
    for(auto& d:cnt){
        if(d.second>=2){
            ans += d.second * (d.second-1)/2;
        }
    }
    cout<<ans<<endl;
    return 0;
}