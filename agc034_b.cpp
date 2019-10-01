//https://atcoder.jp/contests/agc034/tasks/agc034_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string s; cin>>s;
    string s2;
    REP(i,s.size()){
        auto c0 = s.at(i);
        auto c1 = i+1<s.size()?s.at(i+1):'!';
       if (c0=='B'&&c1=='C') { //BCをまとめて'@'とする
            s2.push_back('@');
            ++i; //進める
        } else {
            s2.push_back(c0);
        }
    }
    //cout<<s2<<endl;
    ll ans=0;
    ll mrk=0;
    for(ll i=s2.size()-1;i>=0;--i){
        auto c = s2.at(i);
        if(c=='A') {
            ans += mrk;
        }else if(c=='@'){
            ++mrk;
        }else {
            mrk=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}