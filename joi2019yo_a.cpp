//https://atcoder.jp/contests/joi2019yo/tasks/joi2019_yo_a
//A - ソーシャルゲーム (Social Game)
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll A,B,C; cin>>A>>B>>C;
    ll wv=7*A+B;
    ll ans = C/wv;
    ll ans0 = ((C+wv-1)/wv)*7; //bonusもらった場合
    C = C - ans*wv;
    ans *= 7;
    ans += ((C+A-1) / A);
    cout<<min(ans,ans0)<<endl;
    return 0;
}