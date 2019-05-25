//AtCoder ABC031 A - ゲーム
#include <bits/stdc++.h>
using namespace std;
using li=int64_t;

int main() {
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    int A,D;
    cin>>A>>D;
    int ans = max((A+1)*D,A*(D+1));
    cout<<ans<<endl;
    return 0;
}