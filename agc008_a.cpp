//https://atcoder.jp/contests/agc008/tasks/agc008_a
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
    ll x,y; cin>>x>>y;
    ll ans=INT64_MAX;
    if(x==y){
        ans=0;
    }else{
        //すすんで、-おす
        ll tmp=-y-x;
        if(tmp>=0) ans=min(tmp+1,ans);
        //-おす、すすんで、-おす
        tmp=x-y;
        if(tmp>=0) ans=min(tmp+2,ans);
        //-おして、すすむ
        tmp=y-(-x);
        if(tmp>=0) ans=min(tmp+1,ans);

        //すすむだけ
        tmp=y-x;
        if(tmp>=0) ans=min(tmp,ans);
        //-おす、すすんで、-おす
        //tmp=x-y;
        //if(tmp>=0) ans=min(tmp+2,ans);
        //-おして、すすむ
        //tmp=y-(-x);
        //if(tmp>=0) ans=min(tmp+1,ans);
    }
    cout<<ans<<endl;
    return 0;
}