//https://atcoder.jp/contests/abc043/tasks/arc059_b
//a_a,aa を探索?
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string s; cin>>s;
    FOR(i,0,s.size()-1){
        if(s.at(i)==s.at(i+1)){
            cout<<i+1<<" "<<i+2<<endl;
            return 0;
        }
    }
    FOR(i,0,s.size()-2){
        if(s.at(i)==s.at(i+2)){
            cout<<i+1<<" "<<i+3<<endl;
            return 0;
        }
    }
    cout<<-1<<" "<<-1;
    return 0;
}