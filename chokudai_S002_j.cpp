//https://atcoder.jp/contests/chokudai_S002/tasks/chokudai_S002_j
//J - GCD β
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
template<class T>bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1; } return 0;}

vector< ll > divisor(int64_t n) {
  vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int main() {
    ll N; cin>>N;
    vector<pair<ll,ll>> abn(N);
    REP(i,N){
        ll A,B;
        cin>>A>>B;
        abn.at(i).first=A;
        abn.at(i).second=B;
    }

    auto divs_f = divisor(abn.at(0).first);
    auto divs_s = divisor(abn.at(0).second);
    divs_f.insert(divs_f.end(), divs_s.begin(), divs_s.end());

    auto check_func = [&](ll v){
        FOR(i,1,abn.size()){
            const auto& ab=abn.at(i);
            if(ab.first%v!=0&&ab.second%v!=0) return false;
        }
        return true;
    };
    ll ans=1;
    for(const auto& v:divs_f){
        if(check_func(v)){
            ans=max(v,ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}