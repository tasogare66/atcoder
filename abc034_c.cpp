//AtCoder ABC034 C - 経路
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int MOD=1000000007;
constexpr int WH_MAX=1e5+2;
static int dp[WH_MAX]={};
#if 1
int main()
{
    lli w=4;
    lli h=3;
#if LOCAL&01
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>w>>h;
    //vector<int> dp(w+2,0);
    dp[w]=1;
	for(int y=h;y>=1;--y){
        for(int x=w;x>=1;--x){
            dp[x] += dp[x+1];
            dp[x] %= MOD;
        }
#if LOCAL
        for(int i=1;i<=w;++i){
            cout<<dp[i]<<",";
        }
        cout<<endl;
#endif        
    }
    cout<<dp[1]<<endl;
    return 0;
}
#else
constexpr int WH_MAX=1002;//1e5+2;
static int dp[WH_MAX][WH_MAX]={{}};
 
int main() {
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    lli w=4;
    lli h=3;
    cin>>w>>h;
	dp[h][w] = 1;
	for(int y=h;y>=1;--y){
        for(int x=w;x>=1;--x){
            dp[y][x] += (dp[y+1][x] + dp[y][x+1])%MOD;
        }
    }
    cout<<dp[1][1]<<endl;
    return 0;
}
#endif