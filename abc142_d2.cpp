//https://atcoder.jp/contests/abc142/tasks/abc142_d
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//return first  素数
//return second いくつ
template< typename T >
std::pair<std::vector<T>, std::vector<T>> prime_factor_decomp(T n) {
    std::vector<T> p, e;
    T m = n;
    for (T i = 2; i * i <= n; i++) {
        if (m % i != 0) continue;
        T c = 0;
        while (m % i == 0) c++, m /= i;
        p.push_back(i);
        e.push_back(c);
    }
    if (m > 1) {
        p.push_back(m);
        e.push_back(1);
    }
    return std::make_pair(p, e);
}

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll A,B; cin>>A>>B;    
    ll gcdv = __gcd(A,B);
    auto ans = prime_factor_decomp<ll>(gcdv);
    cout<<ans.first.size()+1<<endl;
    return 0;
}