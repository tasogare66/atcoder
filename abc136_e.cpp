//https://atcoder.jp/contests/abc136/tasks/abc136_e
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
  sort(begin(ret), end(ret));
  return (ret);
}

int main() {
    ll N,K; cin>>N>>K;    
    vector<ll> an(N);
    ll sum=0;
    for(auto&& a:an){
        cin>>a;
        sum+=a;
    }
    //sumの約数もとめる
    auto divs = divisor(sum);
    sort(divs.begin(),divs.end(),greater<ll>()); //約数を降順に調べていく
    for(auto candidate:divs){
        vector<ll> rtbl(N); //modとった残り
        REP(i,N) rtbl[i] = (an[i] % candidate);
 
    }
    return 0;
}