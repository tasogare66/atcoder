//https://atcoder.jp/contests/chokudai_S001/tasks/chokudai_S001_i
//I - 和がNの区間
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
int main(){
#if LOCAL&01
    std::ifstream in("./test/sample-4.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    //尺取りのほうがよいか
    ll N; cin>>N;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }

    ll ans=0;
    for(ll l=0,r=0,sum=0; l<N; sum -= an.at(l++)){
        while(r<N && sum+an.at(r) <= N){
            sum += an.at(r++);
            if(sum==N)++ans;
        }
    }
#if 0
    FOR(l,0,N){
        while(sum<N && r<N){
            sum += an.at(r);
            ++r;
        }
        //処理

        if(l==r){ //追いついたらなんとかする
        }
    }
#endif
    // FOR(l,0,N){
    //     sum += an.at(l);
    //     while(sum<N && r<N){
    //         sum += an.at(r);
    //         ++r;
    //     }
    //     dump(l,r,sum);
    //     if (sum==N) {
    //         ++ans;
    //     }else{
    //         --r;
    //         sum -= an.at(r);
    //     }
    //     if (l==r-1) {
    //         ++r;
    //     }
    //     sum -= an.at(l);
    // }
    cout<<ans<<endl;
    return 0;
}
int main_() {
    //累積和 + 二分探索
#if LOCAL&01
    std::ifstream in("./test/sample-2.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<ll> an(N);
    vector<ll> sums;
    sums.reserve(N+1);
    sums.emplace_back(0);
    ll sum=0;
    for(auto&& a:an){
        cin>>a;
        sum += a;
        sums.emplace_back(sum);
    }

    ll ans=0;
    FOR(i,0,N){
        ll val=sums[i]+N;
        auto it = lower_bound(sums.begin()+i,sums.end(),val);
        if(*it==val) ++ans;
    }
    cout<<ans<<endl;

    return 0;
}