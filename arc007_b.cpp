//https://atcoder.jp/contests/arc007/tasks/arc007_2
//B - 迷子のCDケース
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
    ll N,M; cin>>N>>M;    
    vector<ll> pm(M);
    for(auto&& p:pm){
        cin>>p;
    }
    vector<ll> cd(N+1); //cdがどこに入ってる
    REP(i,N+1){
        cd.at(i)=i;
    }
    ll prev=0;
    for(const auto& p:pm){
        swap(cd.at(prev),cd.at(p));
        prev=p;
    }
    FOR(i,1,N+1){
        auto it= find(cd.begin(),cd.end(),i);
        cout<<distance(cd.begin(),it)<<endl;
    }
    return 0;
}