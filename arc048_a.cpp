//https://atcoder.jp/contests/arc048/tasks/arc048_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll A,B; cin>>A>>B;
    ll ans=0;
    if(A*B<0){
        ans=B-A-1;
    }else{
        ans=B-A;
    }
    cout<<ans<<endl;
    return 0;
}