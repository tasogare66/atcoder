//https://atcoder.jp/contests/abc136/tasks/abc136_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N; 
    ll ans=0;
    FOR(i,1,N+1){
        auto s=to_string(i);
        if(s.size()%2==1)++ans;
    }
    cout<<ans<<endl;   
    return 0;
}