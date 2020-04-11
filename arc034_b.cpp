//https://atcoder.jp/contests/arc034/tasks/arc034_2
//B - 方程式
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

ll digit_sum(ll val){
    ll result=0;
    while(val>0){
        result += (val%10);
        val /= 10;
    }
    return result;
}

ll digit_num(ll val){
    return log10(val) + 1;
}

int main() {
    ll N; cin>>N;    
    ll loop_cnt=digit_num(N) * 9;

    auto check_func = [&](ll in_val){
        in_val += digit_sum(in_val);
        return (in_val == N);
    };

    vector<ll> ans;
    FOR(i,0,loop_cnt+1){
        ll val=N-i;
        if (check_func(val)) {
            ans.push_back(val);
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(const auto& v:ans){
        cout<<v<<endl;
    }
    return 0;
}