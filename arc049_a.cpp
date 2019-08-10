//https://atcoder.jp/contests/arc049/tasks/arc049_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string S; cin>>S;
    vector<ll> abcd(4);
    for(auto&& v:abcd){
        cin>>v;
    }    
    for(ll i=3;i>=0;--i){
        S.insert(abcd[i],"\"");
    }
    cout<<S<<endl;
    return 0;
}