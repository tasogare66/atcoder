//https://atcoder.jp/contests/arc052/tasks/arc052_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string S; cin>>S;
    ll val=0;
    for(const auto& s:S){
        if(s>='0'&&s<='9'){
            val*=10;
            val+=s-'0';
        }
    }
    cout<<val<<endl;
    return 0;
}