//AtCoder ABC120 B - K-th Common Divisor
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
ll lcm(ll num1,ll num2){
    return num1 / __gcd(num1,num2) * num2;
}
vector< int64_t > divisor(int64_t n) {
  vector< int64_t > ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll A,B,K; cin>>A>>B>>K;
    ll v=__gcd(A,B); //vの約数
    auto tbl=divisor(v);
    cout<<tbl[tbl.size()-K]<<endl;
    return 0;
}