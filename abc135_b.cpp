//https://atcoder.jp/contests/abc135/tasks/abc135_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<ll> pn(N);
    for(auto&& p:pn){
        cin>>p;
    }
    auto orig=pn;
    sort(pn.begin(),pn.end());
    ll cnt=0;
    REP(i,pn.size()){
        if(orig[i]!=pn[i]){
            ++cnt;
        }
    }
    cout<<(cnt<=2?"YES":"NO")<<endl;
    return 0;
}