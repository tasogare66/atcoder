//https://atcoder.jp/contests/arc014/tasks/arc014_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    //先頭1,赤
    cout<<(N%2==1?"Red":"Blue")<<endl;
    return 0;
}