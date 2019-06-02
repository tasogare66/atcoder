//AtCoder ABC041 B - 直方体
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
constexpr lli MOD=1e9+7;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    lli A,B,C;
    cin>>A>>B>>C;
    lli ans=(A*B%MOD)*C%MOD;
    cout<<ans<<endl;
    return 0;
}