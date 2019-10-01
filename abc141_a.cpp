//https://atcoder.jp/contests/abc141/tasks/abc141_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string s; cin>>s;    
    map<string,string> tbl={{"Sunny","Cloudy"}, {"Cloudy","Rainy"}, {"Rainy","Sunny"}};
    cout<<tbl[s]<<endl;
    return 0;
}