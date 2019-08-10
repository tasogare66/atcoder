//https://atcoder.jp/contests/abc134/tasks/abc134_c
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    vector<ll> sa=an;
    sort(sa.begin(),sa.end(),greater<ll>());
    for(const auto&a: an){
        if(a==sa[0]) cout<<sa[1]<<endl;
        else cout<<sa[0]<<endl;
    }
    return 0;
}