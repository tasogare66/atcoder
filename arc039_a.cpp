//https://atcoder.jp/contests/arc039/tasks/arc039_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string A,B; cin>>A>>B;
    auto calc=[](const string& a, const string& b){
        ll ia=stoi(a);
        ll ib=stoi(b);
        if (ia>=100&&ia<=999&&ib>=100&&ib<=999) return ia-ib;
        return INT64_MIN;
    };
    ll ans=calc(A,B);
    //a
    for(ll p=0;p<3;++p){
        string ta=A;
        for(ll i=0;i<=9;++i){
            assert(p<ta.size());
            ta[p]='0'+i;
            ans=max(calc(ta,B),ans);
        }
    }
    //b
    for(ll p=0;p<3;++p){
        string tb=B;
        for(ll i=0;i<=9;++i){
            assert(p<tb.size());
            tb[p]='0'+i;
            ans=max(calc(A,tb),ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}