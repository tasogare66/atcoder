//https://atcoder.jp/contests/jsc2019-qual/tasks/jsc2019_qual_a
//第一回日本最強プログラマー学生選手権-予選-
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll M,D; cin>>M>>D;
    ll ans=0;
    FOR(m,1,M+1){
        FOR(d,1,D+1){
            ll d1=d%10;
            ll d10=d/10;
            if(d1>=2&&d10>=2&&d1*d10==m) ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}