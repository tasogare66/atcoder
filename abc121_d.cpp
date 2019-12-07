//https://atcoder.jp/contests/abc121/tasks/abc121_d
//D - XOR World
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
int main() {
    auto calc = [](ll dif){
        ll b=0;
	    switch(dif % 4) {
	    case 0: b=dif; break;
	    case 1: b=1; break;
        case 2: b=dif+1; break;
        case 3: b=0; break;
	    }
        return b;
    };
#if LOCAL&0
    ll tmp=0;
    FOR(i,1,3+4+8+16+32+64+128+1){
        tmp ^= i;
        cout<<i<<":"<<tmp<<","<<calc(i)<<endl;
        assert(tmp==calc(i));
    }
#endif
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll A,B; cin>>A>>B;
    ll ans = calc(B) ^ calc(A-1);
    cout<<ans<<endl;
	return 0;
}