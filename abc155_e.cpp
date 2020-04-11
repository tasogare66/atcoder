//https://atcoder.jp/contests/abc155/tasks/abc155_e
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

//f(3456)=min{f(345)+6,f(346)+4}
ll solve(const string& N) {
    vector<vector<ll>> dp(N.size()+1,vector<ll>(2,0)); //0:そのまま, 1:+1
    dp[0][1]=1;
    FOR(i,0,N.size()){
        ll digit = N.at(i)-'0';
        if (digit==0){
            dp[i+1][0]=dp[i][0];
        }else{
            ll s0 = dp[i][0]+digit;
            ll s1 = dp[i][1]+(10-digit)%10;
            dp[i+1][0]=min(s0,s1);
        }

        ++digit;
        if (digit>=10){
            dp[i+1][1]=dp[i][1];
        }else{//同じ
            ll s0 = dp[i][0]+digit;
            ll s1 = dp[i][1]+(10-digit)%10;
            dp[i+1][1]=min(s0,s1);
        }
    }
    return dp[N.size()][0];
}

ll test(ll t=36){
    auto maisuu = [](ll v){
        ll ret=0;
        while(v>0){
            ret += (v%10);
            v /= 10;
        }
        return ret;
    };

    ll minn = INT32_MAX;
    ll oo,ii;
    FOR(i,t,99999+1){
        auto o = i-t;
        ll tmp = maisuu(i) +maisuu(o); 
        if (chmin(minn, tmp)){
            oo = o;
            ii = i;
        }               
    }
    //dump(t, ii, oo, minn);
    return minn;
}

int main(){
#if 0
    dump(solve("60"));
    FOR(i, 1, 5000){
        auto a=test(i);
        auto b=solve(std::to_string(i));
        if(a!=b) dump(i,a,b);
    }
    return 0;
#endif
#if LOCAL&0
    //std::ifstream in("./test/sample-1.in");
    std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    string N; cin>>N;
    ll ans = solve(N);
    cout<<ans<<endl;
    return 0;
}

int main_() {
    //test(432); return 0;
    // FOR(i, 36, 5000){
    //     test(i);
    // }
    // return 0;
 #if LOCAL&01
     std::ifstream in("./test/sample-2.in");
     //std::ifstream in("./input.txt");
     std::cin.rdbuf(in.rdbuf());
 #else
     cin.tie(0);
     ios::sync_with_stdio(false);
 #endif
    string N; cin>>N;
    ll ans=INT64_MIN;
    vector<ll> sums_d; //反対から累積和
    vector<ll> sums_p; //反対か
    ll sum=0;
    ll sump=0;
    FOR(i,0,N.size()){
        ll digit = N.at(i)-'0';
        sump += digit;
        //sumps_p.push_back(sump);
    }

    for(ll i=N.size()-1;i>=0;--i){
        ll digit = N.at(i)-'0';
        //sump += digit;
        //sums_p.push_back(sump);
        ll v = 10 - digit - 1;
        sum += v;
        sums_d.push_back(sum);
    }
    sums_d.push_back(sum+1);

    //ll ans=INT64_MAX;
    for(ll i=0;i<=sums_p.size();++i){
        ll tmp=sums_p.at(i)+sums_d.at(i+1);
        ans = min(ans,tmp);
    }
    cout<<ans<<endl;

    return 0;
}