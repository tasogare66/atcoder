//https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_a
//A - 電子レンジ (Microwave)
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
    ll A,B,C,D,E; cin>>A>>B>>C>>D>>E;
    ll ans=0;
    if (A<0){
        if (B>0){
            //cold
            ans+=abs(A)*C;
            ans+=D;
        } else{
            ans+=(B-A)*C;
        }
        A=0;
    }
    assert(ans>=0);
    if (B>0){
        ans += (B-A)*E;
    }
    cout<<ans<<endl;

    return 0;
}