//https://atcoder.jp/contests/arc054/tasks/arc054_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll L,X,Y,S,D; cin>>L>>X>>Y>>S>>D;
    auto calc = [&](ll ilen, double r){
        double len=ilen;
        return len/(double)(Y+r*X);
    };
    //時計回り
    ll dist=D-S>=0?D-S:L-(S-D);
    double ans1 = calc(dist,1);
    auto ans=ans1;
    //反対
    if (X<Y){
        ll dist2=S-D>=0?S-D:L-(D-S);
        double ans2 = calc(dist2,-1);
        ans=min(ans1,ans2);
    }
    cout<<fixed<<std::setprecision(10)<<ans<<endl;
    return 0;
}