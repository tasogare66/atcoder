//https://atcoder.jp/contests/arc081/tasks/arc081_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
constexpr ll MOD=1e9+7;
int main() {
    ll N; cin>>N;
    string S1,S2; cin>>S1>>S2;
    enum class Type {
        ROW, COL,
    };
	auto check_rc = [&](ll p) {
		return (S1.at(p) == S2.at(p)?Type::COL:Type::ROW);
	};
    auto add_pos = [](Type t){
        return (t==Type::COL)?1:2;
    };

    ll ans = 0;
    auto prev_rc = check_rc(0);
    ll pos = add_pos(prev_rc);
    if (prev_rc == Type::COL){
        ans = 3;
    } else {
        ans = 3*2;
    }

    while(pos<S1.size()){
        auto rc = check_rc(pos);
        if (prev_rc == Type::COL) {
            ans *= 2; //row,col両方
        } else {
            if (rc == Type::ROW) ans *= 3;
        }
        ans %= MOD;
        pos += add_pos(rc);
        prev_rc = rc;
    }
    cout<<ans<<endl;
    return 0;
}