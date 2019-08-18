//https://atcoder.jp/contests/abc138/tasks/abc138_d
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
struct Data{
    ll count=0;
    ll value=0;
    vector<ll> ch;
    vector<ll> pa;
};
vector<Data> node;
void dfs(ll no, ll sum){
    auto& cur=node[no];
    cur.value = sum+cur.count;
    for(auto& nex:cur.ch){
        dfs(nex, cur.value);
    }
}
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,Q; cin>>N>>Q;
    node.resize(N+1);
    for(ll i=1;i<N;++i){
        ll a,b; cin>>a>>b;
        node[a].ch.push_back(b);
        node[b].pa.push_back(a);
    }
    REP(i,Q){
        ll p,x; cin>>p>>x;
        node[p].count += x;
    }
    //rootから
    dfs(1,0);
    for(ll i=1;i<node.size();++i){
        if(i!=1) cout<<" ";
        cout<<node[i].value;
    }
    cout<<endl;
    return 0;
}