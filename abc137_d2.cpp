//https://atcoder.jp/contests/abc137/tasks/abc137_d
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
struct Info{
    ll A;
    ll B; //day
};
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N, M; cin>>N>>M;    
    vector<Info> tbl(N);
    //unordered_map<ll,ll> cntd;
    unordered_map<ll,deque<Info*>> daytbl;
    for(auto&& t: tbl){
        cin>>t.A>>t.B;
        daytbl[t.A].push_back(&t);
        //cntd[t.A]++;
    }

    ll ans=0;
    priority_queue<ll> candidate;
    for(ll i=1;i<=M;++i){
        for(const auto& d:daytbl[i]){
            candidate.push(d->B);
        }
        if(!candidate.empty()){
            ans+=candidate.top();
            candidate.pop();
        }
    }
    cout<<ans<<endl;
    return 0;
}