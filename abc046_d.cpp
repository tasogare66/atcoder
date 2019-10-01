//https://atcoder.jp/contests/abc046/tasks/arc062_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string s; cin>>s;
    ll ans=0;
    ll g=0,p=0;
    REP(i,s.size()){
        //gのがおおくなるように
        if(s[i]=='g') {
            //p出せるなら出す
            if(p<g){
                ++p;
                ++ans;
            } else {
                ++g;
            }
        } else {
            //相手p
            //p出せるなら出す
            if(p<g){
                ++p;
            } else {
                ++g;
                --ans;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}