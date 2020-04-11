//https://atcoder.jp/contests/abc077/tasks/arc084_a
//AtCoder ABC077 C - Snuke Festival
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&01
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N;
    cin>>N;
    vector<vector<ll>> abc(3,vector<ll>(N));
    for(ll i=0;i<3;++i){
        for(auto && v:abc[i]){
            cin>>v;
        }
        sort(abc[i].begin(),abc[i].end());
    }
 
    vector<ll> d0(N+1,0);
    constexpr int a=0, b=1, c=2;
    for(ll i=0;i<abc[b].size();++i){
        auto itr = lower_bound(abc[a].begin(),abc[a].end(),abc[b][i]); //FIXME:せばめる 
        auto d = distance(abc[a].begin(),itr);
        d0[i+1]=d0[i]+d;
    }

    vector<ll> d1(N+1,0);
    for(ll i=0;i<abc[c].size();++i){
        auto itr = lower_bound(abc[b].begin(),abc[b].end(),abc[c][i]);
        auto d = distance(abc[b].begin(), itr);
        ll num=d0[d];
        d1[i+1]=d1[i]+num;
    }

    cout<<d1[N]<<endl;

    return 0;
}