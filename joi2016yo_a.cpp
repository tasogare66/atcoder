//https://atcoder.jp/contests/joi2016yo/tasks/joi2016yo_a
//A - 科目選択 (Selecting Subjects)
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    vector<ll> sub0(4);
    vector<ll> sub1(2);
    for(auto&& s:sub0){
        cin>>s;
    }
    for(auto&& s:sub1){
        cin>>s;
    }
    sort(sub0.begin(),sub0.end(),greater<ll>());
    sort(sub1.begin(),sub1.end(),greater<ll>());
    ll ans=0;
    ans=accumulate(sub0.begin(),sub0.begin()+3,0);
    ans+=sub1.at(0);
    cout<<ans<<endl;
    return 0;
}