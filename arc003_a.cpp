//https://atcoder.jp/contests/arc003/tasks/arc003_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    string rn; cin>>rn;
    ll sc=0;
    for(const auto& c:rn){
         sc += max(4-(c-'A'),0);
    } 
    double ans = (double)sc / (double)N;
    cout<<fixed<<std::setprecision(10)<<ans<<endl;
    return 0;
}