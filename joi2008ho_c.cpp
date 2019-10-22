//https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c
//第７回日本情報オリンピック 本選（オンライン）
//くじびきと同様
//a,bの二重ループは回す o(n^2)
//m-a-b=c+dがとれるかの判定,c+dはあらかじめ配列をつくっておいてsortしておく、ここを2分探索する
//mの得点をさらに2分探索する
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,M; cin>>N>>M;
    vector<ll> pn(N);
    for(auto && p:pn){
        cin>>p;
    }
    pn.emplace_back(0); //選択しないもいれる

    vector<ll> c_dtbl; //c+dのtable
    for(auto c:pn){
        for(auto d:pn){
            c_dtbl.push_back(c+d);
        }
    }
    sort(c_dtbl.begin(),c_dtbl.end());

    auto check_func = [&](ll m){ //mとれる?
        for(auto a:pn){
            for(auto b:pn){
                auto c_d=m-a-b;
                auto c_dM=M-a-b;
                if (c_d<0) continue;
                auto it = lower_bound(c_dtbl.begin(),c_dtbl.end(), c_d);
                if (it != c_dtbl.end() && *it>=c_d && *it<=c_dM){
                    return true;
                }
            }
        }
        return false;
    };

    ll lb=0,ub=M+1;
    while(ub-lb>1){
        ll mid=(ub+lb)/2;
        if(check_func(mid)){
            lb=mid;
        }else {
            ub=mid;
        }
    }
    cout<<lb<<endl;
    return 0;
}
