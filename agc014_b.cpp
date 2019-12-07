//https://atcoder.jp/contests/agc014/tasks/agc014_b
//B - Unplanned Queries
//根までの経由に置き換える
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,M; cin>>N>>M;
    vector<ll> cnt(N+1);
    REP(i,M){
        ll a,b;
        cin>>a>>b;
        ++cnt.at(a);
        ++cnt.at(b);
    }
    for(const auto& c:cnt){
        if(c%2!=0) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}