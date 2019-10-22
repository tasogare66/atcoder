//https://atcoder.jp/contests/joi2015yo/tasks/joi2015yo_c
//C - 気象予報士 (Weather Forecaster)
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll H,W; cin>>H>>W;
    vector<string> ch(H);
    for(auto&& c:ch){
        cin>>c;
    }
    REP(y,H){
        auto& c=ch.at(y);
        REP(x,W){
            ll idx=-1;
            for(ll pt=0;x-pt>=0;++pt){
                if (c.at(x-pt)=='c') {
                    idx=pt;
                    break;
                }
            }
            if(x!=0) cout<<" ";
            cout<<idx;
        }
        cout<<endl;
    }
    return 0;
}