//https://atcoder.jp/contests/abc145/tasks/abc145_d
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
constexpr ll MOD=1e9+7;
template< typename T >
using Matrix = vector< vector< T > >;

static const int Max=1e6+1;
int dp[Max][Max]={};

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
//    const int max=10000;//1e6+1;
//    vector<vector<int>> dp(max,vector<int>(max,0));
    int X,Y; cin>>X>>Y;
    FOR(y,0,Y+1){
        FOR(x,0,X+1){
            dp[y][x]=0;
        }
    }
    dp[0][0]=1;
    FOR(y,1,Y+1){
        FOR(x,1,X+1){
            if(x-2>=0)dp[y][x]+=dp[y-1][x-2];
            dp[y][x]%=MOD;
            if(y-2>=0)dp[y][x]+=dp[y-2][x-1];
            dp[y][x]%=MOD;
        }
    }
    cout<<dp[Y][X]<<endl;
    return 0;
}