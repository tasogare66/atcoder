//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    vector<ll> pt(5);
    for(auto&& p:pt){
        cin>>p;
    }
    ll k; cin>>k;
    bool ans=(pt[4]-pt[0]<=k);
    cout<<(ans?"Yay!":":(")<<endl;
    return 0;
}