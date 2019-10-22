//https://atcoder.jp/contests/abc026/tasks/abc026_d
//D - 高橋君ボール1号
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
    double A,B,C; cin>>A>>B>>C;
    double lb=0, ub=500;    
    REP(i,100){
        double t=(lb+ub)/2.0;
        double ft = A*t+B*sin(C*t*M_PI)-100.0;
        if (ft<0){
            lb=t;
        } else {
            ub=t;
        }
    }
    cout<<fixed<<std::setprecision(10)<<lb<<endl;
    return 0;
}