//https://atcoder.jp/contests/arc008/tasks/arc008_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-3.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    ll a=((N+9)/10)*100;
    ll b=(N/10)*100+(N-(N/10)*10)*15;
    cout<<min(a,b)<<endl;
    return 0;
}