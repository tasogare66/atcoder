//AtCoder ABC080 C - Shopping Street
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N;
    cin>>N;
    vector<ll> ff(N);
    for(auto&& f:ff){ //bitにして
        ll v=0;
        for(int i=0;i<10;++i){
            v<<=1;
            ll fin;
            cin>>fin;
            v+=fin;
        }
        f=v;
    }
    vector<vector<ll>> ptbl(N,vector<ll>(11));
    for(auto&& pt:ptbl){
        for(auto&& p:pt){
            cin>>p;
        }
    }
    //全探索
    ll end=1<<10;
    ll ans=INT64_MIN;
    for(ll i=1;i<end;++i){ //0は不可
        ll gain=0;
        for(ll j=0;j<ff.size();++j){
            ll msk = (ff[j] & i);
            //bitをカウント
            auto num = __builtin_popcountll(msk);
            gain += ptbl[j][num];
        }
        ans=max(ans,gain);
    }
    cout<<ans<<endl;
    return 0;
}