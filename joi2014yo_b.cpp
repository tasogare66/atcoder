//https://atcoder.jp/contests/joi2014yo/tasks/joi2014yo_b
//B - 投票 (Vote)
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,M; cin>>N>>M;//競技,委員の数
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    vector<ll> bm(M);
    for(auto&& b:bm){
        cin>>b;
    }
    vector<ll> vote(N,0);
    REP(i,bm.size()){
        ll b=bm.at(i);
        REP(j,an.size()){
            if(b<an.at(j))continue;
            ++vote.at(j);
            break;
        }
    }
    ll ans=-1;
    ll vmax=0;
    REP(i,vote.size()){
        if(vmax<vote.at(i)){
            vmax=vote.at(i);
            ans=i;
        }
    }
    cout<<ans+1<<endl;
    return 0;
}