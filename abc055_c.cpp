//AtCoder ABC055 C - Scc Puzzle
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N,M;
    cin>>N>>M;
    // ll cnum=N*2+M;
    // ll ans=cnum/4;
    // cout<<ans<<endl;
    ll snum=N+M/2;
    ll ccnum=M/2;
    ll ans=min(ccnum,snum/(ll)2);
    cout<<ans<<endl;
    return 0;
}