//https://atcoder.jp/contests/arc047/tasks/arc047_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,L; cin>>N>>L;
    string S; cin>>S;
    ll cnt=1;
    ll ans=0;
    for(const auto& c:S){
        if(c=='+'){
            ++cnt;
        }else{
            --cnt;
            cnt=max((ll)1,cnt);
        }
        if(cnt>L){
            ++ans;
            cnt=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}