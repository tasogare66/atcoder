//https://atcoder.jp/contests/agc037/tasks/agc037_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    string S; cin>>S;
    ll ans=0;
    string prev{S.at(0)}; ++ans;
    string cur;
    FOR(i,1,S.size()){
        cur.push_back(S.at(i));
        if (cur!=prev){
            prev=cur;
            cur.clear();
            ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}