//https://atcoder.jp/contests/agc036/tasks/agc036_a
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
    ll S; cin>>S;

    ll x1=ceil(sqrt(S)); //繰り上げる
    ll y2=x1;
    ll x2=1;
    ll y1=x1*y2-S;
    assert(S==x1*y2-x2*y1);
    assert(y1>=0);

    cout<<0<<" "<<0<<" ";
    cout<<x1<<" "<<y1<<" ";
    cout<<x2<<" "<<y2<<endl;
    return 0;
}