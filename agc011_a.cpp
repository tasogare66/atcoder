//https://atcoder.jp/contests/agc011/tasks/agc011_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,C,K; cin>>N>>C>>K;
    vector<ll> tn(N);
    for(auto&& t:tn){
        cin>>t;
    }
    sort(tn.begin(),tn.end());
    ll ans=1;
    ll tm=tn[0]+K;
    ll cnt=C;
    FOR(i,1,N){
        --cnt;
        if(cnt<=0||tn[i]>tm){
            //新しいbus
            ++ans;
            tm=tn[i]+K;
            cnt=C;
        }
    }
    cout<<ans<<endl;
    return 0;
}