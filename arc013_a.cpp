//https://atcoder.jp/contests/arc013/tasks/arc013_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,M,L; cin>>N>>M>>L;
    ll P,Q,R; cin>>P>>Q>>R;
    vector<ll> b();
    vector<ll> len(3);
    len[0]=P; len[1]=Q; len[2]=R;
    sort(len.begin(),len.end());
    vector<ll> no={0,1,2};
    ll ans=0;
    do {
#if LOCAL&01
        cout<<len[0]<<","<<len[1]<<","<<len[2]<<endl;
#endif
        ans = max(((N/len[0])*(M/len[1])*(L/len[2])),ans);
    } while( next_permutation(len.begin(), len.end()) );
    cout<<ans<<endl;
    return 0;
}