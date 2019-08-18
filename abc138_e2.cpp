//https://atcoder.jp/contests/abc138/tasks/abc138_e
//TLEする、findで探索
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
    string s,t; cin>>s>>t;
    string ss=s+s; //sを連結

    ll ans=0;
    string::iterator it=ss.begin();
    for(auto c:t){
        auto cur = find(it, ss.end(), c);
        if(cur==ss.end()){
            cout<<-1<<endl;
            return 0;
        }
        auto d=distance(it, cur)+1;
        ans+=d;
        it = cur;
        if (distance(ss.begin(), it)>=s.size()) {
            it -= s.size();
        }
        ++it;
    }
    cout<<ans<<endl;
    return 0;
}