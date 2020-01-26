//https://atcoder.jp/contests/dp/tasks/dp_f
//F - LCS
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
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    string s,t; cin>>s>>t;
    vector<vector<ll>> dp(s.size()+1,vector<ll>(t.size()+1));
    REP(i,s.size()){
        REP(j,t.size()){
            if(s[i]==t[j]){
                dp[i+1][j+1]=dp[i][j]+1;
            }else{
                dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    //cout<<dp[s.size()][t.size()]<<endl;
    dump(dp,s,t);
    static function<void(ll,ll)> print_lcs = [&](ll i, ll j){
        if(i==0||j==0) return;
        if(s[i-1]==t[j-1]){
            print_lcs(i-1,j-1);
            cout<<s.at(i-1);
        }else{
            if(dp[i-1][j]>=dp[i][j-1]){
                print_lcs(i-1,j);
            }else{
                print_lcs(i,j-1);
            }
        }
    };
    print_lcs(s.size(),t.size()); cout<<endl;

    return 0;
}