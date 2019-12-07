//https://atcoder.jp/contests/code-festival-2016-qualb/tasks/codefestival_2016_qualB_b
//B - Qualification simulator
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
template<class T>bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1; } return 0;}
int main() {
    ll N,A,B; cin>>N>>A>>B;
    string S; cin>>S;
    ll ca=0;
    ll cb=0;
    for(const auto& c:S){
        bool res=false;
        if(c=='a') {
            if(ca+cb<A+B) {
                ++ca;
                res=true;
            }
        }
        else if(c=='b'){
            if(ca+cb<A+B&&cb<B){
                res=true;
                ++cb;
            }
        }
        cout<<(res?"Yes":"No")<<endl;
    }
    return 0;
}