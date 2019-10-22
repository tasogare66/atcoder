//https://atcoder.jp/contests/joi2007yo/tasks/joi2007yo_c
//C - シーザー暗号
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
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    string s; cin>>s;    
    for(auto&& c:s){
        c=c-3;
        if(c<'A') c+=26;
        dump(c);
    }
    cout<<s<<endl;
    return 0;
}