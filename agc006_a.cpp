//https://atcoder.jp/contests/agc006/tasks/agc006_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    string s,t; cin>>s>>t;
    ll cnt=0;
    for(;cnt<s.size();++cnt){
        if (strncmp(&s[cnt],&t[0],s.size()-cnt)==0){
            break;
        }
    }
    ll dup=s.size()-cnt;
    ll ans=(s.size()-dup)*2+dup;
    cout<<ans<<endl;
    return 0;
}