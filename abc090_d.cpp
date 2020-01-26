//https://atcoder.jp/contests/abc090/tasks/arc091_b
//D - Remainder Reminder
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main(){
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,K; cin>>N>>K;
    dump(N,K);
    ll rev=0;
    if (K==0){ //0は別で...
        cout<<N*N<<endl;
        return 0;
    }

    //N=10,b=3だと
    //あまりKより下で考えて、N*N - cout している
    //0
    //1 あまり1 ok
    //2 あまり2
    //3 0---    ok
    //4 あまり1 ok
    //5 あまり2
    //6 0--     ok
    //7 あまり1 ok
    //8 あまり2
    //9 0--     ok
    //10 あまり1 (ここはのこりtmp2でやる)
    FOR(b,1,N+1){ //bを固定して,数をもとめる
        auto rest = min<ll>(K-1,b-1);
        auto tmp = (N/b)*(rest+1); //+1は0の分
        auto tmp2 = min(N-(N/b)*b,rest);
        dump(b,rest,tmp,tmp2);
        rev += (tmp+tmp2);
    }
    auto ans = N*N-rev;
    cout<<ans<<endl;
}

int main_() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,K; cin>>N>>K;
    ll ans=0;
    FOR(b,K+1,N+1){
//        cerr<<"-"<<b<<endl;
        for(ll k=K;k<b;++k){
            ll add = (k!=0)+(N-k)/b;
            ans += add; //k==0は+1しない
//            cerr<<k<<","<<add<<endl;
        }
//        cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}