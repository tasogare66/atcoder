//https://atcoder.jp/contests/joi2009ho/tasks/joi2009ho_b
//B - ピザ
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&0
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll d; cin>>d;
    ll n; cin>>n; //店舗数
    ll m; cin>>m; //注文数
    vector<ll> dn(n-1+2); //店舗位置
    dn.at(0)=0; dn.at(n)=d;
    FOR(i,1,n){
        cin>>dn.at(i);
    }
    sort(dn.begin(),dn.end());
    vector<ll> km(m); //宅配先
    for(auto&& im:km){
        cin>>im;
    }

    ll ans=0;
    for(const auto& im:km){
        auto it = upper_bound(dn.begin(),dn.end(),im);
        // ll tmp=*it-im;
        // tmp=min(im-*(it-1),tmp);
        // ans += tmp;
        ans += min(*it-im,im-*(it-1));
    }
    cout<<ans<<endl;

    return 0;
}