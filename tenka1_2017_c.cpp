//https://atcoder.jp/contests/tenka1-2017-beginner/tasks/tenka1_2017_c
//C - 4/N
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
    FOR(h,1,3501){
        FOR(n,1,3501){
            ll Nhn=N*h*n;
            ll tmp=4*n*h-N*h-N*n;
            if(tmp!=0&&Nhn%tmp==0){
                ll w=Nhn/tmp;
                if (w>0) { 
					cout << h << " " << n << " " << w << endl;
					return 0;
                }
            }
        }
    }
    assert(0);
    return 0;
}