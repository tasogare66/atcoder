//https://atcoder.jp/contests/arc006/tasks/arc006_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-4.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    vector<ll> e(6);
    for(auto&& v:e){
        cin>>v;
    }
    ll B; cin>>B;
    vector<ll> l(6);
    for(auto&& v:l){
        cin>>v;
    }
    ll cnt=0;
    bool has_bonus=false;
    auto itr = find(l.begin(),l.end(), B);
    if(itr != l.end()) has_bonus = true;

    REP(i,e.size()){
        auto it= find(e.begin(),e.end(), l[i]);
        if(it != e.end()) ++cnt;
    }

    ll ans = 0;
    if (cnt == 6){
        ans=1;
    } else if(cnt == 5&&has_bonus){
        ans=2;
    } else if(cnt== 5){
        ans=3;
    } else if(cnt==4){
        ans=4;
    } else if(cnt==3){
        ans=5;
    }
    cout<<ans<<endl;
    return 0;
}