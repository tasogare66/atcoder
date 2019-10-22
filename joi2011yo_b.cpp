//https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_b
//B - 指輪 (Ring)
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string s; cin>>s;
    ll N; cin>>N;
    vector<string> rn(N);
    for(auto&& r:rn){
        cin>>r;
        r += r;
    }
    ll ans=0;
    for(const auto& r:rn){
        auto pos = r.find(s);
        if (pos != string::npos) ++ans;
    }
    cout<<ans<<endl;
    return 0;
}