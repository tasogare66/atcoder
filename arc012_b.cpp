//https://atcoder.jp/contests/arc012/tasks/arc012_2
//B - アキレスと亀
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
    ll N; cin>>N;
    double va,vb; cin>>va>>vb;
    double L; cin>>L;
    REP(i,N){
        double t=L/va;
        L=t*vb;
    }
    cout<<fixed<<std::setprecision(10)<<L<<endl;
    return 0;
}