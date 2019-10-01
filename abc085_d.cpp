//https://atcoder.jp/contests/abc085/tasks/abc085_d
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    enum class Type{
        A,B
    };
    ll N,H; cin>>N>>H;
    vector<pair<ll,Type>> abn;
    REP(i,N){
        ll a,b; cin>>a>>b;
        abn.emplace_back(a,Type::A);
        abn.emplace_back(b,Type::B);
    }
    sort(abn.begin(),abn.end(),[](const auto& a,const auto& b){ return a.first>b.first;});

    ll ans=0;
    ll pt=0;
    while(H>0){
        auto& atk=abn.at(pt);
        if (atk.second == Type::B) {
            H -= atk.first;
            ++ans;
            ++pt;
        } else {
            auto h = H+atk.first-1;
            ans += (h/atk.first);
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}