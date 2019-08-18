//https://atcoder.jp/contests/abc138/tasks/abc138_e
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
    unordered_map<char,vector<ll>> chpos_tbl; //a-z
    REP(i,ss.size()){ //連結したやつで
        chpos_tbl[ss[i]].push_back(i);
    }

    ll ans=0;
    ll idx=-1;
    ll multip=0;
    for(auto c:t){
        auto it = chpos_tbl.find(c);
        if(it == chpos_tbl.end()){
            cout<<-1<<endl;
            return 0;
        }
        auto nx = upper_bound(it->second.begin(), it->second.end(), idx); //upper_boundだった
        ans = multip*s.size() + *nx + 1;
        idx = *nx;
        if (*nx >= s.size()) {
            ++multip;
            idx -= s.size();
        }
    }
    cout<<ans<<endl;
    return 0;
}