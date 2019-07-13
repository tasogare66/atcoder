//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    vector<ll> tbl(5);
    for(auto&& t:tbl){
        cin>>t;
    }
    ll minr_id=-1;
    ll minr=10;
    REP(i,tbl.size()){
        auto r=tbl[i]%10;
        if(r!=0&&minr>r){
            minr=r;
            minr_id=i;
        } 
    }
    ll ans=0;
    REP(i,tbl.size()){
        if(i==minr_id){
            ans += tbl[i];
        } else {
            ans += ((tbl[i]+9) / 10)*10;
        }
    }
    cout<<ans<<endl;
    return 0;
}