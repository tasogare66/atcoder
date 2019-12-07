//https://atcoder.jp/contests/ddcc2017-final/tasks/ddcc2017_final_b
//B - GCDロボット
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
ll lcm(ll num1,ll num2){
    return num1 / __gcd(num1,num2) * num2;
}
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,Z; cin>>N>>Z;
    vector<ll> an(N);
    vector<ll> gv;
    for(auto&& a: an){
        cin>>a;
        gv.push_back(__gcd(a,Z));
    }
    dump(gv);
    ll lcmv=1;
    for(const auto& v:gv){
        lcmv=lcm(v,lcmv);
    }
    cout<<lcmv<<endl;

    return 0;
}