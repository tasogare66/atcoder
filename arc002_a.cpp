//https://atcoder.jp/contests/arc002/tasks/arc002_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll Y; cin>>Y;
    bool ans=false;
    if(Y%4==0) {
        ans=true;
    }    
    if(Y%100==0&&Y%400!=0) {
        ans=false;
    }
    cout<<(ans?"YES":"NO")<<endl;
    return 0;
}