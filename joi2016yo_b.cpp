//https://atcoder.jp/contests/joi2016yo/tasks/joi2016yo_b
//B - ゼッケンの交換 (Swapping Bibs)
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N, M; cin>>N>>M;    
    vector<ll> an(N+1);
    FOR(i,1,N+1){
        cin>>an.at(i);
    }
    FOR(k,1,M+1){
        FOR(i,1,N){
            if (an.at(i)%k > an.at(i+1)%k) {
                swap(an[i],an[i+1]);
            }
        }
        dump(an);
    }

    FOR(i,1,N+1){
        cout<<an.at(i)<<endl;
    }

    return 0;
}