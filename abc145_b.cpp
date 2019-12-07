//https://atcoder.jp/contests/abc145/tasks/abc145_b
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
    string S; cin>>S;  
    ll tmp=N/2;
    auto outno = [](){
        cout<<"No"<<endl;
        exit(0);
    };
    if(N%2==1)outno();
    REP(i,tmp){
        if(S.at(i)!=S.at(tmp+i)){
            outno();
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}