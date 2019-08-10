//https://atcoder.jp/contests/arc015/tasks/arc015_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    double n; cin>>n;
    double t=(9.0/5.0*n)+32.0;
    cout<<fixed<<std::setprecision(10)<<t<<endl;
    return 0;
}