//https://atcoder.jp/contests/code-festival-2017-qualc/tasks/code_festival_2017_qualc_a
//A - Can you get AC?
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string S; cin>>S;
    bool ans=false;
    FOR(i,0,S.size()-1){
        if(S.at(i)=='A'&& S.at(i+1)=='C') ans=true;
    }
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}