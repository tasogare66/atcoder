//https://atcoder.jp/contests/abc089/tasks/abc089_d
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
struct Info {
    ll m_a;
    ll m_val=0;
    ll m_sum=0;
    const Info* m_prev=nullptr;
};
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll H,W,D; cin>>H>>W>>D;
    vector<vector<Info>> aij(H+1,vector<Info>(W+1));
    unordered_map<ll,pair<ll,ll>> posmap;
    FOR(y,1,H+1){
        FOR(x,1,W+1){
            ll a; cin>>a;
            aij.at(y).at(x).m_a=a;
            posmap[a]={x,y};
        }
    }
    ll Q; cin>>Q;
    vector<pair<ll,ll>> lrs(Q);
    for(auto&& lr:lrs){
        cin>>lr.first>>lr.second;
    }

    FOR(y,1,H+1){
        FOR(x,1,W+1){
            auto& info = aij.at(y).at(x);
            auto n = info.m_a + D;
            if (n<=H*W) {
                auto& it = posmap.at(n); //次pos
                info.m_val = abs(it.first-x) + abs(it.second-y);
                //info.m_prev = &aij.at(it.second).at(it.first);
            }
        }
    }
    //累積和
    auto get_info = [&](ll n)->Info&{
        const auto& it = posmap.at(n);
        return aij.at(it.second).at(it.first);
    };
    FOR(n,1,H*W+1){
        if(n+D<=H*W){
            auto& a = get_info(n);
            auto& b = get_info(n+D);
            b.m_sum = a.m_sum + a.m_val;
        }
    }

    for(const auto& lr:lrs){
        ll ans = 0;
        ll ans2 = 0;
        auto l = lr.first;
        auto r = lr.second;
        // while(l!=r){
        //     auto& it = posmap.at(l);
        //     const auto& a = aij.at(it.second).at(it.first);
        //     assert(l==a.m_a);
        //     l += D;
        //     ans += a.m_val;
        // }
        auto rv = get_info(r).m_sum;
        auto lv = get_info(l).m_sum;
        ans2 = rv - lv;
        cout<<ans2<<endl;
    }

    return 0;
}