//https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_D
//最長増加部分列
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#include "../longest_increasing_subsequence.cpp"

int main() {
    ll n; cin>>n;
    vector<ll> an(n); 
    for(auto&& a:an){
        cin>>a;
    }   
    auto ans = longest_increasing_subsequence(an,true);
    cout<<ans<<endl;
    return 0;
}