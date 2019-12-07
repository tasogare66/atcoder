//https://atcoder.jp/contests/arc016/tasks/arc016_2
//B - 音楽ゲーム
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    vector<string> x19(N+1);
    x19.at(0)=".........";
    FOR(i,1,N+1){
        cin>>x19.at(i);
    }
    ll ans=0;
    FOR(i,1,N+1){
        const auto& p=x19.at(i-1);
        const auto& x=x19.at(i);
        FOR(j,0,x.size()){
            if(x.at(j)=='x') ++ans;
            else if(x.at(j)=='o'&&p.at(j)!='o') ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}