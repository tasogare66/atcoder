//https://atcoder.jp/contests/abc032/tasks/abc032_d
//AtCoder ABC032 D - ナップサック問題
#include <bits/stdc++.h>
using namespace std;
using li=int64_t;

int N,W;
vector<int> vn;
vector<int> wn;
vector<vector<li>> dp;

li search(int i, int w){ //重さは引いていく
    if (i>=N){
        return 0;
    }
    if (dp[i][w] >= 0) {
        return dp[i][w];
    }
    auto cv=vn[i];
    auto cw=wn[i];
    li ret=0;
    // if (i>=N) {
    //     ret=0;
    // } else
    if (w < cw) { //入らない
        ret = search(i+1,w);
    } else{
        ret = std::max(search(i+1,w), search(i+1,w-cw)+cv); //いれない,いれる
    }
    dp[i][w]=ret;
    return ret;
}

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    cin>>N>>W;
    vn.resize(N);
    wn.resize(N);
    for(int i=0;i<N;++i){
        cin>>vn[i]>>wn[i];
    }
    dp.resize(N+1);
    for(auto&& t:dp){
        t.resize(W+1,-1);
    }
    auto ans = search(0,W);
    cout<<ans<<endl;
    return 0;
}