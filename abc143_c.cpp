//https://atcoder.jp/contests/abc143/tasks/abc143_c
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    string S; cin>>S;    
    string ans;
    char prev=0;
    for(auto& c:S){
        if(prev!=c) ans.push_back(c);
        prev=c;
    }
    cout<<ans.length()<<endl;
    return 0;
}