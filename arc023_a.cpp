//https://atcoder.jp/contests/arc023/tasks/arc023_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll Y,M,D; cin>>Y>>M>>D;
    auto func = [](ll y,ll m, ll d){
        if(m==1||m==2){
            y-=1;
            m+=12;
        }
        ll ret=365*y;
        ret += y/4 - y/100 + y/400 + (306*(m+1))/10 + d - 429;
        return ret;
    };
    ll ans=func(2014,5,17)-func(Y,M,D);
    cout<<ans<<endl;
    return 0;
}