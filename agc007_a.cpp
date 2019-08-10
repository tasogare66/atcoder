//https://atcoder.jp/contests/agc007/tasks/agc007_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll H,W; cin>>H>>W;
    vector<string> ah(H); //0base
    FOR(i,0,H){
        cin>>ah[i];
    }
    ll cnt=0;
    REP(y,H){
        REP(x,W){
            if(ah[y][x]=='#') ++cnt;
        }
    }
    bool ans=(cnt==H+W-1);
    cout<<(ans?"Possible":"Impossible")<<endl;
    //assert(ans);
    return 0;
}