//https://atcoder.jp/contests/chokudai_S002/tasks/chokudai_S002_k
//K - 種類数 β
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
template<class T>bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1; } return 0;}

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<pair<ll,ll>> abn(N);
    map<ll,ll> val2index;
    REP(i,N){
        ll A,B;
        cin>>A>>B;
        abn.at(i).first=A;
        abn.at(i).second=B;
        if(val2index.count(A)==0) {
            val2index[A]=val2index.size();
        }
        if(val2index.count(B)==0){
            val2index[B]=val2index.size();
        }
    }
    uf_tree uft(val2index.size());
    for(const auto& p:abn){
        uft.unite(val2index[p.first],val2index[p.second]);
    }
    auto ans = N-uft.size()+1;
    cout<<ans<<endl;
#if 0
    ll N; cin>>N;
    vector<pair<ll,ll>> abn(N);
    REP(i,N){
        ll A,B;
        cin>>A>>B;
        abn.at(i).first=A;
        abn.at(i).second=B;
        valnum[A]++;
        valnum[B]++;
    }
    set<ll> ans;
    for(const auto& p:abn){
        if(valnum[p.first] == 1) {
            ans.insert(p.first);
            continue;
        } else if(valnum[p.second] == 1){
            ans.insert(p.second);
            continue;
        }
        //入ってないほう
        if(ans.count(p.first)==0){
            ans.insert(p.first);
            continue;
        }else{
            ans.insert(p.second);
        }
    }
    cout<<ans.size()<<endl;    
#endif
    return 0;
}