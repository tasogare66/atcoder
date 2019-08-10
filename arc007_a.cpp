//https://atcoder.jp/contests/arc007/tasks/arc007_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    char X; cin>>X;
    string s; cin>>s;
    string ans;
    for(const auto& c:s){
        if(c!=X) ans.push_back(c);
    }
    cout<<ans<<endl;
    return 0;
}