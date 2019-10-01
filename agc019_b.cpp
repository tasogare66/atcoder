//https://atcoder.jp/contests/agc019/tasks/agc019_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string A; cin>>A;
    unordered_map<char,ll> numtbl;
    for(const auto& c:A){
        ++numtbl[c];
    }
    ll ans=1; //いれかえないやつ
    ans += A.size() * (A.size()-1) / 2;
    for(const auto& p: numtbl){
        ans -= p.second * (p.second-1) / 2;
    }
    cout<<ans<<endl;
    return 0;
}