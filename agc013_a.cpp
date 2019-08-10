//https://atcoder.jp/contests/agc013/tasks/agc013_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    vector<ll> zg;//zougen
    zg.reserve(N);
    FOR(i,0,N-1){
        if(an[i]<an[i+1]){ //増加
            zg.push_back(1);
        } else if(an[i]>an[i+1]){ //減少
            zg.push_back(-1);
        } //増減なし
    }
    ll flg=zg[0];
    ll ans=1;
    FOR(i,1,zg.size()){
        if(flg!=zg[i]){
            if(i+1<zg.size()){
                ++i;
                flg=zg[i];
            } else {
                flg=zg[i];
            }
            ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}