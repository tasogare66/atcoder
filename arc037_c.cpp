//https://atcoder.jp/contests/arc037/tasks/arc037_c
//C - 億マス計算
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
    ll N,K; cin>>N>>K;
    vector<ll> an(N),bn(N);
    for(auto&& a:an){
        cin>>a;
    }
    for(auto&& b:bn){
        cin>>b;
    }
    sort(an.begin(),an.end());
    sort(bn.begin(),bn.end());

    auto check_func = [&](ll val){ //以下がk個以上?
        ll count=0;
        for(const auto& a:an){ //ai*bj<=mid -> bj <= mid/ai
            ll cur=val/a;
            auto it=upper_bound(bn.begin(),bn.end(),cur);
            count += distance(bn.begin(),it);
        }
        return (count>=K);
    };
    ll lb=1,ub=(*an.rbegin())*(*bn.rbegin())+1;
    while(ub-lb>1){
        ll mid=(ub+lb)/2;
        if(check_func(mid)){ //ubより
            ub=mid;
        }else{
            lb=mid;
        }
    }
    cout<<ub<<endl;
    return 0;
}