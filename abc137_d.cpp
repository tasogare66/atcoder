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
    // sort(tbl.begin(),tbl.end(),[](const auto&a, const auto& b){
    //     if(a.A==b.A){
    //         return a.B>a.B;
    //     }
    //     return (a.A<b.A);
    // });
    ll ans=0;
    deque<Info*> candidate;
    for(ll i=1;i<=M;++i){
        candidate.insert(candidate.end(),daytbl[i].begin(), daytbl[i].end());
        sort(candidate.begin(), candidate.end(),[](const auto&a, const auto& b){
            return a->B > b->B;
        });
        if(candidate.size()>0){
            ans += candidate[0]->B;
            candidate.erase(candidate.begin());
        }
    }
    cout<<ans<<endl;
    return 0;
}