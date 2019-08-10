//https://atcoder.jp/contests/arc012/tasks/arc012_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string day; cin>>day;
    unordered_map<string,ll> tbl = {
        {"Sunday",0},
        {"Monday",5},
        {"Tuesday",4},
        {"Wednesday",3},
        {"Thursday",2},
        {"Friday",1},
        {"Saturday",0},
    };
    cout<<tbl[day]<<endl;
    return 0;
}