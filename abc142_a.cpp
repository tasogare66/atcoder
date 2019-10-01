//https://atcoder.jp/contests/abc142/tasks/abc142_a
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
    double n=N;
    double ans;
    if(N%2==0){
        //ぐう
        ans = 0.5;
    }else{
        double tmp=N/2;
        ans=(tmp+1.0)/n;
    }
    cout<<fixed<<std::setprecision(10)<<ans<<endl;
    return 0;
}