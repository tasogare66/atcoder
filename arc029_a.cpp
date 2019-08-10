//https://atcoder.jp/contests/arc029/tasks/arc029_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<ll> tn(N);
    for(auto&& t:tn){
        cin>>t;
    }
    sort(tn.begin(),tn.end(),greater<ll>());
    ll a=0,b=0;
    for(const auto& t:tn){
        if(a>b){
            b+=t;
        } else {
            a+=t;
        }
    }
    cout<<max(a,b)<<endl;
    return 0;
}