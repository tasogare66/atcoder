//https://atcoder.jp/contests/code-festival-2016-quala/tasks/codefestival_2016_qualA_a
//A - CODEFESTIVAL 2016
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string s; cin>>s;
    string ans;
    REP(i,s.size()){
        ans.push_back(s.at(i));
        if(i==3)ans.push_back(' ');
    }
    cout<<ans<<endl;
    return 0;
}