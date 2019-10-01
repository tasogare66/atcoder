//https://atcoder.jp/contests/abc139/tasks/abc139_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string s; cin>>s;
    string t; cin>>t;
    ll ans=0;
    REP(i,s.size()){
        if(s[i]==t[i])++ans;
    }    
    cout<<ans<<endl;
    return 0;
}