//https://atcoder.jp/contests/abc069/tasks/arc080_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll H, W; cin>>H>>W;
    ll N; cin>>N;
    vector<pair<ll,ll>> an(N);
    REP(i,N){
        ll a; cin>>a;
        an.at(i) = {a,i+1};
    }
    sort(an.begin(),an.end(),[](const auto& a,const auto& b){return a.first > b.first;});
    vector<vector<ll>> ans(H,vector<ll>(W));
    ll p = 0;
    for(auto&& hh :ans){
        for(auto&& ww : hh){
            ww = an.at(p).second;
            an.at(p).first--; //減らす
            if(an.at(p).first <= 0) ++p;
        }
    }
    //1つおきにreverse
    REP(y,ans.size()){
        if(y%2==1) reverse(ans[y].begin(),ans[y].end());
    }
    REP(y,ans.size()){
        REP(x,ans.at(y).size()){
            if(x!=0) cout<<" ";
            cout<<ans[y].at(x);
        }
        cout<<endl;
    }
    return 0;
}
