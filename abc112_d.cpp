//https://atcoder.jp/contests/abc112/tasks/abc112_d
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

vector< int64_t > divisor(int64_t n) {
  vector< int64_t > ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret),greater<ll>()); //降順
  return (ret);
}

int main() {
    ll N,M; cin>>N>>M;

    auto divs = divisor(M); //約数,降順
    for(auto v:divs){
        if(N*v<=M) {
            cout<<v<<endl;
            return 0;
        }
    }

    return 0;
}