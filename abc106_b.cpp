//AtCoder ABC106 B - 105
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
//約数を列挙 O(√N)
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
    ll N; cin>>N;
    ll ans=0;
    for(ll i=1;i<=N;++i){
        if (i%2==1){
            auto tmp = divisor(i);
            if(tmp.size()==8) ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}