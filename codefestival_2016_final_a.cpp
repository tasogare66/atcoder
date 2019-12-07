//https://atcoder.jp/contests/cf16-final/tasks/codefestival_2016_final_a
//A - Where's Snuke?
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll H,W; cin>>H>>W;
    ll ah,aw;
    REP(h,H){
        REP(w,W){
            string s; cin>>s;
            if(s=="snuke") {
                ah=h;
                aw=w;
            }
        }
    }
    cout<<(char)('A'+aw)<<ah+1<<endl;
    return 0;
}
