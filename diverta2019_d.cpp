//
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
template<size_t SIZE, class T> inline size_t array_size(T (&arr)[SIZE]) {
    return SIZE;
}

//約数の列挙
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
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    lli N=8;
    cin>>N;
    lli ans=0;
    lli i=1;
    auto lst=divisor(N); //k(m+1)=N なので約数-1を調べる
    for (const auto& d:lst){
        auto m=d-1;
        if(m>0&&N/m==N%m){
            ans+=m; 
        }
    }
    cout<<ans<<endl;
    return 0;
}