//https://atcoder.jp/contests/cf16-final/tasks/codefestival_2016_final_b
//B - Exactly N points
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
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;    
    ll sum=0;
    ll cnt=0;
    FOR(i,1,N+1){
        sum+=i;
        if(sum>=N) {
            cnt=i;
            break;
        }
    }
    ll d=sum-N;
    FOR(i,1,cnt+1){
        if (d!=i) cout<<i<<endl;
    }
    return 0;
}