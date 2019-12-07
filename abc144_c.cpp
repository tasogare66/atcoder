//https://atcoder.jp/contests/abc144/tasks/abc144_c
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

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
    ll N; cin>>N;
    auto pe = prime_factor_decomp(N);
    vector<ll> t;
    REP(i,pe.first.size()){
        REP(j,pe.second.at(i)){
            t.emplace_back(pe.first.at(i));
        }
    }
    sort(t.begin(),t.end());//,greater<ll>());
    ll a=1,b=1;
    for(const auto& v:t){
        ll as=a*v+b;
        ll bs=b*v+a;
        if(as<bs){
            a*=v;
        }else {
            b*=v;
        }
    }
    cout<<(a-1)+(b-1)<<endl;
    return 0;
}