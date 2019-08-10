//https://atcoder.jp/contests/arc020/tasks/arc020_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll A,B; cin>>A>>B;    
    if (abs(A)<abs(B)) {
        cout<<"Ant"<<endl;
    } else if(abs(A)>abs(B)) {
        cout<<"Bug"<<endl;
    } else {
        cout<<"Draw"<<endl;
    }
    return 0;
}