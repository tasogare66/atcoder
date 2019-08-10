//https://atcoder.jp/contests/arc035/tasks/arc035_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string s; cin>>s;
    bool ans=true;
    for(ll i=0;i<s.size()/2;++i){
        char a=s[i];
        char b=s[s.size()-1-i];
        if(a=='*'||b=='*')continue;
        if(a!=b) ans=false;
    }
    cout<<(ans?"YES":"NO")<<endl;
    return 0;
}